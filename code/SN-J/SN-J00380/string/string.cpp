#include <bits/stdc++.h>
using namespace std;
long long n,a,len,l,r,ans;
char x;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++) s+=x;
	}
	len=s.size();
	l=0,r=len-1;
	while(true){
		if(len%2==0&&r==l+1) break;
		else{
			if(l==r) break;
		}
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
