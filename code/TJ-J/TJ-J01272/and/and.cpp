#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[10001];
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	cout<<a[n];
	fclose(stdin);
	fclose(stdout);

	return 0;
}

