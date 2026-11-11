#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long ans=0,len=0;
string s;
//vector<pair<int,char>>g;
//vector<pair<int,char>>g1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		len+=x;
		for(int i=1;i<=x;i++){
			s+=c;
		}
		/*if(i!=1){
			if(g[g.size()-1].second==c){
				g[g.size()-1].first+=x;
				continue;
			}
		}
		g.push_back({x,c});*/
	}
	string s1=s;
	//s1.reserve(s1.begin(),s1.end());
	for(long long i=1;i<=len;i++){
		if(s[i]!=s1[len-i-1]){
			ans++;
		}
	}
	cout<<(ans+1)/2;
	/*n=g.size();
	for(int i=0;i<n;i++){
		g1.push_back(g[n-i-1]);
	}
	for(int i=0;i<n;i++){
		if(g[i].second!=g1[i].second&&g[i].first==g1[i].first){
			ans+=g[i].first;
		}else if(g[i].second==g1[i].second&&g[i].first!=g1[i].first){
			ans+=abs(g[i].first-g1[i].first);
		}else{
			ans+=min(g[i].first,g1[i].first);
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
