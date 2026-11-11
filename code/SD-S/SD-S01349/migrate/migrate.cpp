#include<bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
using namespace std;
const int N=2e6+5,inf=1e9;
int n;
ll d,x[N];
pair<int,int>dx[N];
void A(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1){
		cout<<"0\n";
		return ;
	}
	ll p=d/(x[n]-x[n-1]);
	if(n<2*p||p<=1) cout<<0<<"\n";
	else cout<<n-2*p+1<<"\n";
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int ans=0;
	for(int l=1;l<n;l++){
		dx[l]={0,1};
		int lx=l,s;
		for(int i=l+1;i<=n;i++){
			dx[i]={inf,0};
			while(x[i]-x[lx]>d) lx++;
			for(int j=lx;j<i;j++){
				if(dx[j].fr+1<dx[i].fr) dx[i]={dx[j].fr+1,dx[j].sc};
				else if(dx[j].fr+1==dx[i].fr) dx[i]={dx[i].fr,dx[i].sc+dx[j].sc};
			}
			if(dx[i].sc==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c==11||c==12) A();
		else solve();
	}
	return 0;
	//16:21
	/*
	I suddenly remember my classmate Milk_Dragon(uid:964579).
	*/
	//16:47
	/*
	false le, I'm angry.
	*/
	//17:07
	/*
	O(n^3)
	*/
	//17:17
	/*
	A
	*/
}
