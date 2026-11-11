#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=m-1;i>=1;i--){
		ans=ans and a[i];
	}
	cout<<ans;
	return 0;
} 
