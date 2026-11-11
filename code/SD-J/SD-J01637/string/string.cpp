#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	string s,s2;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]&&s.size()-1-i>=s.size()/2){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

