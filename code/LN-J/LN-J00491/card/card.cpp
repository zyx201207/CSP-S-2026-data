#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],cnt[M],pre[M],d[N],s[N],l[N],c[N],nxt[M],nxt2[N],ans[N];
bool b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(cnt[a[i]]!=0){
            if(b[a[i]]){
                d[i]+=d[pre[a[i]]]-1;
                d[pre[a[i]]]=1;
                nxt[a[i]]=i;

            }
            else{
                d[pre[a[i]]]++;
                d[i]--;
                nxt[a[i]]=i;
                nxt2[pre[a[i]]]=i;
                b[a[i]]=1;
            }
        }
        pre[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=0;i<n;i++){
        memset(s,0,sizeof(s));
        memset(l,0,sizeof(l));
        d[i]=0;
        d[nxt[a[i]]]++;
        for(int j=i+1;j<=n;j++){
            if(s[j-1]+d[j]>0) l[j]=max(l[j-1],l[j]);
            if(s[j-1]>0&&nxt2[j]>nxt2[l[j]]&&d[j]>0){
                d[j]=0;
                d[nxt[a[j]]]++;
            }
            s[j]=s[j-1]+d[j];
            if(s[j]<=0) c[j]++;
            if(d[j]>0) l[j+1]=j;
        }
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]=max(ans[a[i]],c[i]);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
