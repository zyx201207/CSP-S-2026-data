#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char q[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>q[i];
		for(int j=1;j<=a[i];j++){
			s+=q[i];
		}
	}
	s='1'+s;
	int ans=0;
	for(int i=1;i<=(s.size()+1)/2-1;i++){
		int j=(s.size()+1)/2+i;
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
