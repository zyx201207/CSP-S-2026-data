#include<bits/stdc++.h>
using namespace std;
int n,a,t;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	for(int i=0,j=s.size()-1;i<=int(s.size()/2-1);i++,j--) if(s[i]!=s[j]) t++;
	cout<<t;
	return 0;
}
