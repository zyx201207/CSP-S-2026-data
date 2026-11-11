#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;string s;vector<string>v;
bool strin(vector<string> x){
	long long l=x.size();
	vector<string>s1;
	while(l){
		s1.push_back(x[l-1]);
		l--;
	}
	for(long long i=0;i<s1.size();i++){
		if(s1[i]==v[i]){
		}else{
			return false;
		}
	}
	return true;
}
long long cmp(vector<string> x){
	long long ans=0,l1=x.size()/2,l2=x.size()-1;
	for(long long i=0;i<x.size()/2;i++){
		l2--;
		if(x[i]!=x[l2]){
			ans++;
		}
	}
	return ans;
}
long long cmp1(vector<string> x){
	long long l=x.size()-1;
    long long ans=0,l1=l/2,l2=l+1;
	    for(long long i=0;i<l/2;i++){
		    l2--;
		    if(x[i]!=x[l2]){
			    ans++;
		}
		
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>s;
		for(long long i=1;i<=a;i++){
			v.push_back(s);
		}
	}
	if(strin(v)){
		cout<<0;
	}else{
		if(v.size()%2==0){
		cout<<cmp(v);
	}else{
		cout<<cmp1(v);
	}
	}	

	return 0;
} 

