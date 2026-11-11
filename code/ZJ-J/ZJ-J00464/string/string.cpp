#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005];
char b[1000005];
long long sum,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(sum>=1e9){
		for(int i=1;i<=n/2;i++){
			if(b[i]!=b[n+1-i])cnt+=a[i];
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+b[i];
		}
	}
	long long l=s.size()-1;
	for(int i=0;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[l-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
