#include<bits/stdc++.h>
using namespace std;
char c;
int n,a,u;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) u++;
	}
	cout<<u;
	return 0;
}
