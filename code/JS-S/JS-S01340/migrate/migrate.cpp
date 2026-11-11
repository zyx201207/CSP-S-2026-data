#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,l,ans;
vector<int> a;
int j[2000005];
int dfs(int sum,int x,int y){
    if(x==y){
        j[sum]++;
        return sum;
    }
    int ans=INT_MAX;
    for(int i=x+1;i<=y;i++){
        if(a[i-1]-a[x-1]>d){
            return sum=ans;
        }
        ans=min(ans,dfs(sum+1,i,y));
    }
    return sum=ans;
}
bool pd(int x,int y){
    memset(j,0,sizeof(j));
    int t=dfs(0,x,y);
    if(j[t]==2){
        return 1;
    }else{
        return 0;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int k=1;k<=t;k++){
        a.clear();
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>l;
            if(i==1 or l-a[a.size()-1]<=d){
                a.push_back(l);
            }
        }
        for(int i=1;i<=a.size();i++){
            for(int j=i+1;j<=a.size();j++){
                if(pd(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
