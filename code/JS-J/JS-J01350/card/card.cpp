#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
const int M=3e5;
int n,m;
int a[N+10];
int ans[M+10];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int s[N+10]={0};
        int top=0;
        for(int j=i;j<=n;j++){
            for(int k=top;k>=1;k--){
                if(a[j]==s[k]){
                    top=k-1;
                    break;
                }
            }
            s[++top]=a[j];
        }
        for(int j=1;j<=top;j++){
            ans[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}

