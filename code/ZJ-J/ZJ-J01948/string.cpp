#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string .in","r",stdin);
	//freopen("string.out","w",stdout);
	int n=0;
	cin>>n;
	vector<long long> a;vector<char> b;
	for(long long i=0;i<n;i++){
	  long long u;char m;
	  cin>>u>>m;
	  a.push_back(u);
	  b.push_back(m);
	}
	string s={};
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s.push_back(b[i]);
		}
	}
	string s1={};
	for(long long i=s.size()-1;i>=0;i--){
		s1.push_back(s[i]);
	}
	bool nu=true;
	for(int long long i=0;i<s.size();i++){
		if(s1[i]!=s[i]){
			nu=false;
		}
	}
	long long  count=0;
	long long ds=s.size()/2;
	long long dn=s.size()/2+1;
	long long dm=s.size()/2-1;
	if(nu){
		cout<<0;
	}else{
		if(s.size()%2==0){
		 for(long long i=0;i<dm;i++){
			if(s[i]!=s[i+ds]){
				count++;
			}
		 }
	   }else{
	    for(long long i=0;i<ds;i++){
	    	if(s[i]!=s[dn]){
	    		count++;
			}
		 }	
	  }
	  cout<<count;
	}
	return 0;
}