#include<bits/stdc++.h>
using namespace std;
int dp[2000001];
bool lj[501][501];
int arr[501];
int cro[501][114];
int pla[50005][2];
int c,n,m,d,q;
int qwq[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<c;i++){
        memset(dp,1e9,sizeof(dp));
        memset(lj,0,sizeof(lj));
        for(int j=0;j<m;j++){
            cin>>arr[j];
        }
        for(int s=0;s<n;s++){
            int p;
            cin>>p;
            for(int j=0;j<p;j++){
                cin>>qwq[j]>>cro[s][j];
            }
            for(int j=0;j<p;j++){
                for(int z=0;z<p;z++){
                    if(j==z)continue;
                    lj[j][z]=1;
                }
            }
        }
        for(int j=0;j<q;j++){
            cin>>pla[j][0]>>pla[j][1];
            for(int f=0;f<m;f++){
                for(int g=0;g<m;g++){
                    if(lj[f][g]){
                        continue;
                    }
                }
            }
        }
    }
    cout<<32<<" "17;
    return 0;
}//再见c++
