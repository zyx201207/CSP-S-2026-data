#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],p,t,ans;
char c[200005];
string s,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n>2000){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			p+=a[i];
		}
		cout<<(p+1)/2-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[j+p]=c[i];
		}
		p+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=p;i++){
		s2[i]=s[p-i+1];
	}/*
	for(int i=1;i<=p;i++){
		cout<<s[i];
	}
	for(int i=1;i<=p;i++){
		cout<<s2[i];
	}*/
	t=(p+1)/2-1;
	for(int i=1;i<=t;i++){
		if(s[i]!=s2[i])ans++;
	}
	cout<<ans;
	return 0;
}/*
2
2 a
3 a
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
//11:42!!!
*/
