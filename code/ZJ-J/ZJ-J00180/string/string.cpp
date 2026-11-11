#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	string s="";
	long long l=0;
	while(t--){
		long long n;
		char a;
		cin>>n>>a;
		for(long long i=1;i<=n;i++){
			s+=a;
		}
		l+=n;
	}
	string r=s;
	reverse(r.begin(),r.end());
	double ans=0;
	for(long long i=1;i<=l;i++){
		if(r[i]!=s[i])ans++;
	}
	cout<<ceil(ans/2);
	return 0;
}
