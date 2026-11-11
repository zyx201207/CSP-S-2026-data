#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
