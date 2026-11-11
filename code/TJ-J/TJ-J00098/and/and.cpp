#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
long long n,m,a[MAXN],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(m==0){
		cout<<0;
		return 0;
	} 
	sort(a+1,a+n+1);
	s=a[n];
	for(long long i=1;i<m;i++){
		s&=a[n-i];
	}
	cout<<s;
	return 0;
} 
