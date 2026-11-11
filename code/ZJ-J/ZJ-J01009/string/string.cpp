#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
string s="";
bool check(string s){
	for (int i=1,j=n;i<=n/2+1,j>=n/2-1;i++,j--)
		if (s[i]!=s[j])
			return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if (n==1){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	if (n==2&&c[1]==c[2]){
		cout<<0;
		return 0;
	}
	if (check(s))
		cout<<0;
	else 
		cout<<1;
	return 0;
} 