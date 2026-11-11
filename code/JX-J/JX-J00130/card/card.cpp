#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t[500005],n,m,last[300005],ans[300005],a[500005];
int lb(int x){
    return x&-x;
}
void add(int x,int d){
    while(x<=n){
        t[x]+=d;
        x+=lb(x);
    }
}
int sum(int x){
    int ret=0;
    while(x>0){
        ret+=t[x];
        x-=lb(x);
    }
    return ret;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(last,0,sizeof(last));
        memset(t,0,sizeof(t));;
        for(int j=i;j<=n;j++){
            if(last[a[j]]!=0){
                if(sum(last[a[j]])==0){
                    add(last[a[j]],1);
                    add(j,-1);
                }
            }
            last[a[j]]=j;
        }
        vector<bool> h(m+1,0);
        for(int j=i;j<=n;j++){
            if(sum(j)==0){
                if(h[a[j]]==0){
                    ans[a[j]]++;
                    h[a[j]]=1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    
    return 0;
}