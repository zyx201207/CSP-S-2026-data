#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s,b,ma;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1,j=1;i<=n;i++) {
		cout<<s<<'*';
		b=(i-j)*(a[i]-a[i-1]);
		cout<<s+b<<'*';
		while(s+(i-j)*(a[i]-a[i-1])>m) {
			s-=a[i]-a[j];
			j++;
		}
		s+=b;
		cout<<i<<'*'<<j<<'*'<<s<<endl;
		ma=max(ma,i-j+1); 
	}
	printf("%d\n",ma);
	return 0;
} 
