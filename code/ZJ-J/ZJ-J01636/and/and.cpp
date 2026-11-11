#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-1;i>=n-m;i--){
		s=s&a[i];
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
