#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,ans;
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char ch;
		cin>>x>>ch;cnt+=x;
		while(x--)s+=ch;
	}
	int l=cnt/2,r=cnt&1?l+2:l+1;
	for(int i=1,j=cnt;i<=l,j>=r;i++,j--)
	if(s[i]!=s[j])ans++;
	cout<<ans;
	return 0;
}
