#include<bits/stdc++.h>
using namespace std;
const int MAX=2E5+10;
int n;
long long l,ans=0;
char c[MAX];
long long a[MAX],f[MAX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
		l+=a[i];
		cin>>c[i];
	}
	for(int i=1;i<=l/2;i++){
		int j=1,z=1;
		while(f[j]<=l-i)j++;
		while(f[z]<i)z++;
		if(c[z]!=c[j])ans++;
	}
	cout<<ans;
	return 0;
}
