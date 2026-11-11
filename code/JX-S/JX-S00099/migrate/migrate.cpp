#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int c,t;
int a[200005],b[20005][20005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    for(int numt=1;numt<=t;++numt){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                b[i][j]=INF;
            }
            for(int j=i+1;j<=n;++j){
                b[i][j]=a[j]-a[i];
            }
        }
        int num=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                int cnt=0;
                for(int k=1;k<=j;++k){
                    if(b[i][k]<=d&&b[k][j]<=d)++cnt;
                }
                if(cnt==2) ++num;

            }
        }
        cout<<num;
    }
    return 0;
}
