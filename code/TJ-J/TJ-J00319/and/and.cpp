#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int ans=a[i];
		while(m>0){
			int z=1;
			ans=ans&a[i+z];
			m--;
			z++;
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}
