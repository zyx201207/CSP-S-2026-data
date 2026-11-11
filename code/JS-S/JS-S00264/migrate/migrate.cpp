#include <bits/stdc++.h>
using namespace std;
long long x[5005];
int mp[5005][5005],num[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mp[i][j]=0;
                num[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=1;j<i;j++){
                if(x[i]-x[j]<=d){
                    mp[j][i]=1;
                    num[j][i]=1;
                }
                else mp[j][i]=1000000;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(mp[i][k]+mp[k][j] == mp[i][j]) num[i][j]++;
                    else if(mp[i][k]+mp[k][j] < mp[i][j]){
                        mp[i][j]=mp[i][k]+mp[k][j];
                        num[i][j]=1;
                    }
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(num[i][j]==2) sum++;
        cout<<sum<<endl;
    }
    return 0;
}
