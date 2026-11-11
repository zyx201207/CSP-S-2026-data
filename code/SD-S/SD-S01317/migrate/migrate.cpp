#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
bool check(vector<ll>& b,int l,int r){
	for(int i=l;i<=r;i++){
	}
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ID,t;cin>>ID>>t;
	while(t--){
		ll n,d;cin>>n>>d;
		vector<ll> x(n+1),a(n+1),b(n+1);
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<4){
			cout<<"0\n";
			continue;
		}
		b[0]=1;
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]-1;
			while(b[i]<n&&x[b[i]+1]-x[i]<=d)b[i]++;
		}
		vector<ll> c(n+1);
		for(int i=2;i<=n;i++)c[i]=x[i]-x[i-1];
		bool flag=true;
		for(int i=2;i<n;i++)
			if(c[i]!=c[i+1]){
				flag=false;
				break;
			}
		if(b[b[1]]==n){
			ll i=1,ans=0;
			while(b[i]<n&&i<n-1)ans+=b[i+2]-b[i+1],i++;
			if(b[n-3]==n-1&&b[n-2]==n)ans++;
			cout<<ans<<'\n';
		}else if(flag){
			ll d_=d/c[2],i=1,ans=0;
			if(d_==1){
				cout<<"0\n";
				continue;
			}
			while(b[i]<n&&i<n-1){
				if(b[b[i]-1]==n&&b[b[i]-2]<n)ans++;
				ans+=b[b[i]]-b[b[i]-1],i++;
			}
			cout<<ans<<'\n';
		}else{
			int i=1,ans=0;
			while(b[i]<n&&i<n-1){
				if(b[i]==i)break;
				if(b[i]-1==i)continue;
				if(b[b[i]-1]==n&&b[b[i]-2]<n)ans++;
				ans+=b[b[i]]-b[b[i]-1],i++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
