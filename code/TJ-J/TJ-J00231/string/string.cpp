#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],cnt;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	for(int i=0;i<s.length();i++){
		if(s[i]!=s[s.length()-i-1]){
			cnt++;
			s[s.length()-i-1]=s[i]; 
		}
	}
	cout<<cnt;
	return 0;
}
