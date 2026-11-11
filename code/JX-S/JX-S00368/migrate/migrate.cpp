#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
long long c,t,n,d,cnt;
long long arr[N];
long long dist[5000][5000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        cnt=0;
        memset(arr,0,sizeof(arr));
        memset(dist,-1,sizeof(dist));
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((arr[j]-arr[i])<=d){
                    dist[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int k=n-1;k>=i+1;k--){
                for(int j=n;j>=k;j--){
                    if(dist[i][k]!=-1&&dist[k][j]!=-1){
                        if(dist[i][j]==-1)dist[i][j]=0;
                        dist[i][j]+=(dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dist[i][j]==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
