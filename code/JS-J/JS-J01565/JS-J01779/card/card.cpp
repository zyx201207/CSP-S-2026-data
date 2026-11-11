#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[500005];
int n,m;
int ans[300005];
int a[500005],b[500005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];    
    }
    int t=1;
    while(t<=n){
        for(int i=t;i<=n;i++){
            b[i]=1;
            if(s[a[i]]==0){
                s[a[i]]=i;
            }else{
                for(int j=s[a[i]];j<i;j++){
                    b[j]=0;
                    s[a[j]]=0;
                }
                s[a[i]]=i;
            }
            
        }
        for(int i=t;i<=n;i++){
            if(b[i]==1){
                ans[a[i]]++;
            }  
        }
        memset(s,0,sizeof(s));
        t++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}