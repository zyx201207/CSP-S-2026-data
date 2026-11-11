#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e5+10;
int k[N][40];
int a[N];
int n,m;
bool f[N][40];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        int j=1;
        while(x!=0){
            k[i][j]=x%2;
            x>>=1;
            j++;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=35;j++){
            f[i][j]=1;
        }
    }
    int ans=0;
    for(int i=34;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(f[j][i+1]==0){
                f[j][i]=0;
                continue;
            }
            if(k[j][i]){
                cnt++;
            }
            else f[j][i]=0;
        }
        if(cnt>=m)ans+=1<<(i-1);
        else{
           for(int p=1;p<=n;p++){
                f[p][i]=f[p][i+1];
            }
        }
    }
    cout<<ans;
    return 0;
}
