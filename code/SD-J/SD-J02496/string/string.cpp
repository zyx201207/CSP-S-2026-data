#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long num,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long aa;
		string c;
		cin>>aa>>c;
		num+=aa;
		for(long long j=1;j<=aa;j++){
			s+=c;
		}
	}
	for(long long i=0;i<num/2;i++){
		if(s[i]!=s[num-1-i])ans++;
	}
	cout<<ans;
	return 0;
} 
