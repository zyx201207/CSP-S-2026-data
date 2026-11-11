#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N=2e6+10;
ll x[N];
bool vis[N];
int ans,sum;
void find(int sx,int d){
        ll min1=INT_MAX;
		ll min2=INT_MAX;
    for(int i=1;i<=2;i++){
    	ans=0;
    	if(sx+d&&vis[sx+d]==0){
		    vis[sx+d]=1;
    		ans++;
    		find(sx+d,d);
		}
	} 
	if(ans==2&&min1==min2) sum++;
    return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;	
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		find(0,d);
		cout<<sum<<"\n";
	}
	return 0;
} 
