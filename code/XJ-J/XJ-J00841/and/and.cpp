#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],sum1[N];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum1[i]=(sum1[i-1]) & (sum1[i]);
	}
	
	int maxn=INT_MIN;
	for (int i=1;i<=n;i++){
		if (maxn<(sum1[i] & sum1[i+m]) && i+m<n){
			maxn=(sum1[i] & sum1[i+m-1]);
		}
	}
	
	cout<<a[n];
	return 0;
} 

