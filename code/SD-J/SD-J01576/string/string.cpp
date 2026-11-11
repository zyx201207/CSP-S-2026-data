#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string s1;
	for(int i=0,j=n;i<=n,j>=0;i++,j--){
		s1[i]=s[j];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	int ans=0,m=n/2;
	for(int i=0;i<=m;i++){
		if(s1[i]!=s[i]){
			s[i]=s1[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
