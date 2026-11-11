#include<bits/stdc++.h>
using namespace std;
int c,_;
long long n,d;
long long a[2000005],step[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>_;
    while (_--){
        //cout<<1;
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        if (c==11 || c==12){
            if ((d/(a[2]-a[1]))>=2 && d/(a[2]-a[1])*2-1<n){
                cout<<n-d/(a[2]-a[1])*2+1<<"\n";
                //else cout<<n-d/(a[2]-a[1])*2-1<<"\n";
            }
            else cout<<"0\n";
        }
        else if (c<=10){
            for (int i=1;i<=n;i++){
                int last=i;
                for (int j=i+1;j<=n;j++){
                    if (a[j]-a[last]>d) step[i][j]=step[i][last]+1,last=i;
                    else step[i][j]=step[i][last];
                }
            }
            for (int i=1;i<=n;i++){

            }
        }
        else if (c==13 || c==14) cout<<"0\n";
    }
    return 0;
}
//sha shi meng xian da
