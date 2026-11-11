#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,j=1;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	while(j!=m){
		ans&=a[n-1];
		n--;
		j++;
	}
	cout<<ans;
	return 0;
}
