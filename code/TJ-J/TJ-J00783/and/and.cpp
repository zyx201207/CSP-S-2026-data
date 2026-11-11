#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[200009],n,m,ans=0,ans1=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1); 
	ans=a[n-1];
	ans1=a[n-1];
	for(int i=n-1;i>=n-m ;i--){
	    ans&=a[i];
	} 
	for(int i=n;i>=n-m+11;i--){
	    ans1&=a[i];
	} 
	cout << max(ans,ans1);
    return 0;
}



