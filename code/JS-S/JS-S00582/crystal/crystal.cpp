#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    const int N=500005;
    int a[N];
    int b[N][N];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((a[j]-a[i])>m){
                break;
            }
            b[i][j]=a[j]-a[i];
            // cout<<b[i][j]<<" ";
        }
        // cout<<endl;
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        int ans=0;
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(ans+b[j][i]<m){
                ans=ans+b[j][i];
                cnt++;
            }else{
                maxn=max(maxn,cnt);
                break;
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}
