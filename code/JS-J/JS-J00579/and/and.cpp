#include<bits/stdc++.h>
using namespace std;
const int N=200500;
int n,m;
int a[N];
bool f[N][33]={0};
int sum[100];
long long int ans;
void solve(int x){
    for(int i=1;i<=n;i++){
        if(f[i][x]==0){
            for(int j=0;j<=32;j++){
                if(f[i][j]==1){
                    sum[j]--;
                    f[i][j]=0;
                }
            }
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=0;
        int x=a[i];
        while(x>0){
            f[i][j]=x%2;
            sum[j]+=f[i][j];
            x/=2;
            j++;
        }

    }
    for(int i=32;i>=0;i--){
        if(sum[i]>=m){
            ans+=pow(2,i);
            solve(i);
        }
    }
    cout<<ans;
    return 0;
}
