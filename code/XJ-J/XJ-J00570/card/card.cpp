#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int read(){
    int ret=0,sgn=0,ch=getchar();
    while(ch>'9'||ch<'0'){
        sgn |= ch=='-',ch=getchar();
    }
      while(ch<='9'&&ch>='0'){
        ret=ret*10+ch-'0',ch=getchar();
    }
    return sgn ? -ret:ret;
}
int n,m,a[MAXN],t[MAXN];
int pre[MAXN],ans[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],pre[i]=-1;
    for(int i=n;i>=1;i--){
        if(t[a[i]]==0)t[a[i]]=i+1;
        else pre[i]=t[a[i]];
    }
    for(int i=1;i<=n;i++){
        int thx=i;
        while(thx<=n){
            //cout<<thx<<" ";
            ans[a[thx]]++;
            if(pre[thx]!=-1)thx=pre[thx];
            else thx++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}