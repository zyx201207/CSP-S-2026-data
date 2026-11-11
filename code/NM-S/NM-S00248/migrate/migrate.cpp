#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve1(){
	ll n,d;
	cin>>n>>d;
	vector<ll> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	//sort(v.begin(),v.end());
	vector< vector<int> > dis(n,vector<int>(n));
	vector< vector<ll> > cnt(n,vector<ll>(n));
	for(int i=0;i<n;i++){
		int ptr=i;
		for(int j=i+1;j<n;j++){
			while(ptr<j&&v[j]-v[ptr]>d)ptr++;
			dis[i][j]=dis[i][ptr]+1;
		}
	}
	//for(int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<dis[i][j]<<" ";}cout<<"\n";}cout<<"\n";
	for(int i=0;i<n;i++){
		cnt[i][i]=1;
		int l=i,r=i;
		for(int j=i+1;j<n;j++){
			int sum=0;
			while((l<j&&(dis[i][l]!=dis[i][j]-1))||v[j]-v[l]>d){
				l++;
			}
			r=l;
			while(r<j&&dis[i][r]==dis[i][j]-1){
				sum+=cnt[i][r];
				r++;
			}
			//cout<<i<<" "<<j<<" "<<l<<" "<<r<<"\n";
			cnt[i][j]=sum;
		}
	}
	//for(int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<cnt[i][j]<<" ";}cout<<"\n";}cout<<"\n";
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			ll n,d;
			cin>>n>>d;
			vector<ll> v(n);
			for(int i=0;i<n;i++)cin>>v[i];
			//sort(v.begin(),v.end());
			if(n<=1){
				cout<<"0\n";
			}
			ll diff=v[1]-v[0];
			//cout<<n<<" "<<d<<" "<<diff<<"\n";
			if(diff*2>d)cout<<"0\n";
			else cout<<max(n-d/diff*2+1,0ll)<<"\n";
		}
	}
	else if(c>=13&&c<=14){
	//else if(1){
		while(t--){
			ll n,d;
			cin>>n>>d;
			vector<ll> v(n);
			for(int i=0;i<n;i++)cin>>v[i];
			//sort(v.begin(),v.end());
			ll ans=0;
			for(int i=0;i<n;i++){
				int p1=upper_bound(v.begin(),v.end(),v[i]+d)-v.begin();
				int p2=upper_bound(v.begin(),v.end(),v[i]+2*d)-v.begin()-1;
				ans+=max(p2-p1,0);
			}
			cout<<ans<<"\n";
		}
	}
	/*
	else if(c>=15&&c<=18){
		while(t--){
			ll n,d;
			cin>>n>>d;
			vector<ll> v(n);
			for(int i=0;i<n;i++)cin>>v[i];
			//sort(v.begin(),v.end());
		}
	}
	*/
	else{
		while(t--)solve1();
	}
	return 0;
}
