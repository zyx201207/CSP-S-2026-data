#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long l;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	long long ans=0;
	for(long long i=0;i<l;i++){
		if(s[i]!=s[l-1-i])ans++;
	}
	cout<<ans/2;
	
	
	return 0;
}
