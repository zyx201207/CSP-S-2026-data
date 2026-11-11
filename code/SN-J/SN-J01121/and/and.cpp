#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans<<"\n";
	stdin.fclose();
	stdout.fclose();
	return 0;
}
