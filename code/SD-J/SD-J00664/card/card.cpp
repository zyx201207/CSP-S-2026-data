#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[510000];
map<int,int>mp,mp2;
//set<int>s;
string s;
int dfs(int x){
	int b=1;
	
	for(int i=x;i<=n;i++){
		auto aa=s.find(char(a[i]+'0'));
		//cout<<aa<<endl;
		if(aa!=18446744073709551615){
			//cout<<"%";
			s=s.substr(0,aa); 
			
			mp[a[i]]=i;
		}
		else{
			mp[a[i]]=i;
		}
		s+=(a[i]+'0');
		//cout<<"i="<<i<<" "<<s<<endl;
	}
	//cout<<"s="<<s<<endl;
	for(int i=0;i<s.size();i++){
		mp2[s[i]-'0']++;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//dfs(1);
	for(int i=1;i<=n;i++){
		dfs(i);
		mp.clear();
		s.erase();
	}
	for(int i=1;i<=m;i++){
		cout<<mp2[i]<<" ";
	}
	return 0;
}

