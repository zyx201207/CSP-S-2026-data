#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	string s1;
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s1==s){
		cout<<"0";
	}else{
		int w=s.size();
		long long sum=0;
		for(int i=0,d=w;i<w/2;i++,d--){
			s[d]==s[i];
			sum++;
		}
		cout<<sum;
	}
	return 0;
}
