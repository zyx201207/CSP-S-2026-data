#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],b1[200010],b2[200010],g,sum,ans;
char c[200010];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		g=__gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]/=g;
	}
	for(int i=1;i<=n;i++){
		b1[i]=b1[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		b2[i]=b2[i+1]+a[i];
	}
	sum=(b1[n]>>1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i]&&b1[i-1]+j<=sum;j++){
			s1+=c[i];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i]&&b2[i+1]+j<=sum;j++){
			s2+=c[i];
		}
	}
	for(int i=0;i<sum;i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans*g<<"\n";
	return 0;
}
