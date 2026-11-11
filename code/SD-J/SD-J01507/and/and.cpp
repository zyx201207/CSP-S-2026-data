#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],k,p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(long long int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//cout<<a[n-k+1]; 
	for(int i=n;i>=n-k+1;i--){
		if(a[i]==a[i-1])p++;
	}
	cout<<a[n-k+1-p];
	return 0;
}
