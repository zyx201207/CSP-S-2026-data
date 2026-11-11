#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[200005];
char y[300005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		sum+=x[i];
	}
	sum/=2;
	int o=sum;
	vector<pair<int,char>>a,b;
	for(int i=1;i<=n;i++){
		if(sum>=x[i]){
			a.push_back({x[i],y[i]});
			sum-=x[i];
		}
		else{
			a.push_back({sum,y[i]});
			break;
		}
	}	
	sum=o;
	for(int i=n;i>=1;i--){
		if(sum>=x[i]){
			b.push_back({x[i],y[i]});
			sum-=x[i];
		}
		else{
			b.push_back({sum,y[i]});
			break;
		}
	}
	int j=-1;
	int ans=0;
	for(auto s:a){
		int t=s.first,r=s.second;
		while(j+1<b.size()&&b[j+1].first<=t){
			t-=b[j+1].first;
			if(b[j+1].second!=r) ans+=b[j+1].first;
			j++;
		}
		if(t!=0){
			b[j+1].first-=t;
			if(b[j+1].second!=r) ans+=t;
		}
	}
	cout<<ans;
	return 0;
}
