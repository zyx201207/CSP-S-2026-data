#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int c,t,n,d;
int a[N];
int Min(int l,int r){
    int cnt=0;
    while(l<r){
		int ls=l;
        l=upper_bound(a+l,a+r,a[l]+d)-a-1;
        if(l==ls)return 0;
        cnt++;
    }
    return cnt;
}
int cnt[N],mi;
bool mp[N][N];
void dfs(int ed,int x,int step){
    if(mp[x][step])return;
    if(x==ed){
        cnt[step]++;
        return;
    }
    int far=upper_bound(a+x,a+ed,a[x]+d)-a-1;
    for(int i=x+1;i<=far;i++){
        mp[x][step]=1;
        dfs(ed,i,step+1);
        mp[x][step]=0;
    }
}
void init(){
	for(int i=0;i<n;i++){
        cnt[i]=0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+3;j<n;j++){
				init();
                mi=Min(i,j);
                if(!mi)continue;
                dfs(j,i,0);
                if(cnt[mi]==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
