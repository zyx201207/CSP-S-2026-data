#include <bits/stdc++.h>
using namespace std;
long long p,a[10100],sum;
char u[101010909];
char c[10101];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=p;j<a[i]+p;j++)u[j]=c[i];
			p+=a[i];
	}
		long long t=(p-1)/2;
		int o=p-1;
		for(int i=1;i<=t;i++){
			if(u[i]!=u[o])sum++;
			o--;
		}cout<<sum;
return 0;
}
