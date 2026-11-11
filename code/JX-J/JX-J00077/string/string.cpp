#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+='2';
	for(int i=1;i<=n;i++){
		long long t;
		string a;
		cin>>t>>a;
		for(int i=1;i<=t;i++){
			s+=a;
		}
	}
	int nn=s.size()-1;
	//cout<<s<<" "<<nn<<endl;
	for(int i=1;i<=nn/2;i++){
		if(s[i]!=s[nn+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
