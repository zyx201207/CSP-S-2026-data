#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005]; 
char c[200005],f[200005];
long long sum,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		f[i]=c[i];
	}
	for(int i=0;i<n/2;i++)if(!(f[i]==f[n-i-1]))sum++;
	printf("%lld",sum);
	return 0;
} 
