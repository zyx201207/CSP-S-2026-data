#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5,MAX=pow(2,31);
const string k="000000000000000000000000000000";
ll n,m,a[N],ans=0;
bool vis[N];
string s[N];
string f(ll x){
	string h=k,to;
	while(x>0){
		to+=(char)(x%2+'0');
		x/=2;
	}
	for(int i=0;i<to.size();i++)h[i]=to[i];
	return h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=f(a[i]);
	}
	for(int j=29;j>=0;j--){
		ll sum=0;
		for(int i=1;i<=n;i++)sum+=(!vis[i]&&s[i][j]=='1');
		if(sum>=m){
			for(int i=1;i<=n;i++){
				if(s[i][j]=='0')vis[i]=1;
			}
			ans+=pow(2,j);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
