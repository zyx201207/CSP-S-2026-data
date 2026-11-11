#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int MAXM=3003;
int ans[MAXM];
int n,m;
int a[MAXN];
int q[MAXN];
bool f[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++)
            q[k]=0;
        for(int k=1;k<=m;k++)
            f[k]=0;
        int r=0;
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                r=f[a[j]];
            }else{
                q[++r]=a[j];
                f[a[j]]=r;
            }
        }
        for(int j=1;j<=r;j++){
            ans[q[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
         cout<<ans[i]<<'\n'; 
    return 0;
}
//g++ card.cpp -o card -std=c++14 -O2