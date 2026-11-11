#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10009;
ll n,m,a[N],ca[N];
void solveA(){
	ll u=1,cnt=0;
	for(ll i=0;i<=m;i++){
		cnt++;
		if(u==cnt){
			cnt=0;
			u++;
		}
		if(u>=n) break;
	}
	if(u>n) cout<<n<<endl;
	else cout<<u<<endl;
}
void solveB(){
	ll u=1,vi=0;
	ll cnt=a[2]-a[1];
	ll rcnt=cnt;
	for(ll i=0;i<=m;i++){
		vi++;
		if(vi==rcnt+1){
			u++;
			vi=0;
			rcnt+=cnt;
		}
		if(u>=n) break;
	}
	if(u>n) cout<<n<<endl;
	else cout<<u<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios:sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool cntA=true,cntB=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]+1!=a[i]) cntA=false;
		else if(a[i-1]-a[i-2]!=a[i]-a[i-1]) cntB=false;
	}
	if(cntA==true)
		solveA();
	else if(cntB==false){
		solveB();
	}
	else{
		ll ans=1;
		for(ll i=1;i<=m;i++){
			memset(ca,0,sizeof(ca));
			sort(a+1,a+1+n);
			a[1]++;
			for(ll j=1;j<=n;j++){
				ca[j]++;
				for(ll k=j+1;k<=n;k++){
					if(a[k]==a[j]){
						ca[j]++;
						ca[k]++;
					}
				}
			}
			sort(ca+1,ca+1+n);
			cout<<ca[n]<<endl;
			if(ca[n]>ans) ans=ca[n];
		}
		cout<<ans<<endl;
	}
	return 0;
}
