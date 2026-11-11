#include<bits/stdc++.h>
using namespace std;
string s;
long long a,ans=0,sum=0;
char b;
int main(){
freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>b;
		sum+=a;
		for(long long j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[sum-1-i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
} 
