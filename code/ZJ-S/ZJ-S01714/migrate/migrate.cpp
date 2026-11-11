#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2000005;
int c,t,n,cnt=0;
ll a[N],k;
vector <ll> v;
int qu(int x,int y,int &j){
	int ans=0;
	if(upper_bound(v.begin(),v.end(),v[x]+k)-v.begin()-1>j+1) return ans;
	if(lower_bound(v.begin(),v.end(),v[y]-k)-v.begin()<j) return ans;
	ans++;
	ans+=qu(x+1,y,j);
	ans+=qu(x,y-1,j);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int s=1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			v.push_back(a[i]);
		}
		
		for(int i=1;i<n-2;i++){
			//cout<<a[i+1]-k<<' '<<a[i]+k<<'\n';
			if(a[i+1]-a[i]>=k) continue;
			int x=lower_bound(v.begin(),v.end(),a[i+1]-k)-v.begin();
			int y=upper_bound(v.begin(),v.end(),a[i]+k)-v.begin()-1;
			cout<<x<<' '<<y<<'\n';
			
			cnt+=qu(x,y,i);
		}
		
		cout<<cnt<<"\n";
		
		for(int i=1;i<=n;i++) a[i]=0;
		v.erase(v.begin(),v.end());
		cnt=0;
		
		
	}
	
	return 0;
}


/*
0 1
5 2
1 4 5 6 7
*/



