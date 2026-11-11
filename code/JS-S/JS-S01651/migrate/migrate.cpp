#include<bits/stdc++.h>
using namespace std;
int n,T;
long long a[500005],m,d;
void dfs(int x,int y,int sum,int e){
    int l=x,r=x;
    if(e==sum&&x<y)return;
    if(e==sum){
        d++;
        return;
    }
    while(m>a[r]-a[l]){
        r++;
        if(m>=a[r]-a[l]&&r<=y)dfs(r,y,sum,e+1);
        if(r>y)return;
    }
}
bool check(int x,int y){
    int l=x,r=x,sum=0;
    while(l<y){
        if(m>a[r]-a[l]&&r<y){
            r++;
        }else{
            sum++;
            l=r;
        }
    }
    dfs(x,y,sum,0);
    if(d==2)return true;
    return false;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>T>>T;
    while(T--){
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
				d=0;
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
