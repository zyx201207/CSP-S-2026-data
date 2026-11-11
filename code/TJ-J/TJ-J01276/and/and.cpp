#include <bits/stdc++.h>
using namespace std;
const int N=1e6; 
long long n,m,Max=-1;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long temp;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			temp=a[i] & a[i+m];
		}
		if(temp>Max)
			Max=temp;
	}
	cout<<Max;
	return 0;
} 
