#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int num=s.size()-1,ans=0;
	for(int i=0;i<s.size();i++){
		if(i==num||abs(i-num)==1) break;
		if(s[i]!=s[num]) ans++;
		num--;
	}
	cout<<ans;

	return 0;
}
