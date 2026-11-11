#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans[100000];
	int m,n;
	cin>>n>>m;
	int now=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<m;j++){
			int now=a[j]||a[j+1];
		}
		ans[i]=now;
		now=0;
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n-1]<<endl;
	return 0;
}
