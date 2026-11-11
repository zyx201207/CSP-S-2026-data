#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t=0;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			t=a[i];
			b[t]++;
			break;
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<' ';
	}
	scanf("%d",/n);
	return 0;
}
