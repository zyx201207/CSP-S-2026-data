#include<bits/stdc++.h>
using namespace std;
int n,a,m,ans;
string s=" ";
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++)
			s+=b;
		m+=a;
	}
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1])
			ans+=1;
	}
	cout<<ans;
	return 0;
}
