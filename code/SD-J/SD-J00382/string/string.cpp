#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	long long a,m=0;
	char c;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		m+=a;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	long long ans=0;
	for(long long i=0;i<=m/2+1;i++){
		if(m%2==1 && i==m/2+1){
			continue;
		}
		if(s[i]==s[m-i]){
			continue;
		}
		else{
			s[m-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
}
