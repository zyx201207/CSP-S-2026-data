#include<bits/stdc++.h>
using namespace std;
string s;
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s+=b;
		} 
	}
	for(long long i=0;i<=n/2;i++){
		if(s[i]!=s[n+i-1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
