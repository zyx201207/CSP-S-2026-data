#include <bits/stdc++.h>
using namespace std;
long long n,m,a,A[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>A[i];
	}
	sort(A+1,A+1+n);
	a=(n*2-m)/2;
	cout<<A[a];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
