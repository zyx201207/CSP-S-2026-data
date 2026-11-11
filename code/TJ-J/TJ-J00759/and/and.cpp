#include <bits/stdc++.h>
using namespace std;
long long a[100001];
long long b[100000001];
int main(){
	int c=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i]=a[i] and a[j];			
			c++;
		}
	}
	sort(b+1,b+c+1);
	cout<<b[c];
	return 0;
} 
