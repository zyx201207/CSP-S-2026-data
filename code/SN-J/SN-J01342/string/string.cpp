#include<bits/stdc++.h>
using namespace std;

long long n,a,ans;
string b,c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			c+=b;
		}
	}
	int s=c.size();
	for(int i=0;i<s;i++){
		if(i==(s/2+s%2)) break;
		if(c[i]!=c[s-i-1]) ans++;
	}
	cout<<ans;
	
	return 0;
} 



