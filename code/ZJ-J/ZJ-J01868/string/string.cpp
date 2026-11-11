#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<char,int>> a,b,c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char t;int x;
		cin>>x>>t,a.push_back({t,x});
		sum+=x;
	}
	sum/=2;
	int s=sum,i=0;
	while(s){
		if(s>=a[i].second) s-=a[i].second,b.push_back(a[i]);
		else b.push_back({a[i].first,s}),s=0;
		i++;
	}
	s=sum,i=n-1;
	while(s){
		if(s>=a[i].second) s-=a[i].second,c.push_back(a[i]);
		else c.push_back({a[i].first,s}),s=0;
		i--;
	}
	int ans=0;
	for(int i=0,j=0;i<b.size()&&j<c.size();){
		if(b[i].second>c[j].second){
			if(b[i].first!=c[j].first) ans+=c[j].second;
			b[i].second-=c[j].second,c[j].second=0;
		}else{
			if(b[i].first!=c[j].first) ans+=b[i].second;
			c[j].second-=b[i].second,b[i].second=0;
		}
		if(!c[j].second) j++;
		if(!b[i].second) i++;
	}
	cout<<ans<<endl;
} 
