#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll n,a[N],d,sss,ans,sum;
int c,t;
bool c1=1;
void dfs(int x,int y,int k){
    if(a[y]-a[x]>d&&k==1)return;
    if(k==1){
        sss++;
        return;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-x<=d)dfs(i,y,k-1);
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c;
    cin>>t;
    while(t--){
        cin>>n>>d;
        c1=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i!=1&&i!=2){
                if(a[i]-a[i-1]!=a[i-1]-a[i-2])c1=0;
            }
        }
        ans=0;
        if(c1){
            ll tt=d/(a[2]-a[1]);
            tt=tt*2-1;
            if(n<tt||tt==-1||tt==1){
                cout<<0<<endl;
                continue;
            }
            cout<<n-tt<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                sss=0;
                int tmp=i;
                sum=1;
                for(int k=j;k>tmp;k--){
                    if(a[k]-a[tmp]<=d){
                        sum++;
                        if(k==j) break;
                        else{
                            tmp=k;
                            k=j;
                        }
                    }
                }
                if(sum==0){
                    continue;
                }
                dfs(i,j,sum);
                if(sss==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
