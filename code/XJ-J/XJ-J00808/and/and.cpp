#include <bits/stdc++.h> 
using namespace std;
const int N=200000000;
long long n,m,s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	cout<<s[n-m+1];
	
	return 0;
}
