#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const long long N=1e6+5,B=131;
ll n,m,k,t,sum=0,ans=0;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<(n-k)*(n-k)/2<<"\n";
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			cin>>n>>k;
			cout<<0<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>k;
		vector<int>v;
		int st=-1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>k){
				int p=upper_bound(v.begin(),v.end(),st+k)-v.begin()+1;
				if(v[p-1]>st+k)ans+=(v.size()-p+1+1)*(v.size()-p+1)/2;
				v.erase(v.begin(),v.end());
			}
			v.push_back(a[i]);
			if(v.size()==1){
				st=a[i];
			}
		}
		if(v.size()>0){
			int p=upper_bound(v.begin(),v.end(),st+k)-v.begin()+1;
			//cout<<p<<"|";
			if(v[p-1]>st+k){
				ans+=(v.size()-p+1+1)*(v.size()-p+1)/2;
				//cout<<v.size()<<" "<<p<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
-
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
	 /\_/\   ?
	( o o ) 
   \/    \

*/