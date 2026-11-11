#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],s1,s2,k1=1,k2,ans;
char c[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	s1=a[1],s2=a[n];k2=n;
	while(k1<=n&&k2>=1){
		if(s1>=s2){
			if(c[k1]!=c[k2])ans+=s2;
			s1-=s2;
			s2=a[--k2];
		}
		else {
			if(c[k1]!=c[k2])ans+=s1;
			s2-=s1;
			s1=a[++k1];
		}
	}
	cout<<ans/2;
	return 0;
}
