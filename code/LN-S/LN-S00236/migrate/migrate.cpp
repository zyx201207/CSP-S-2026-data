#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N][N]={1},ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate1.in","r",stdin);
    freopen("migrate1.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        int b[N];
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            b[x]=1;
        }
        for(int j=1;j<=n;j++){
            for(int k=j;k<=n;k++){
                if(b[k]==0){
                    a[j][k]=0;
                    continue;
                }
                for(int l=k-d;l<k;l++){
                    a[j][k]+=a[j][l];
                }
                if(a[j][k]==2){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}
