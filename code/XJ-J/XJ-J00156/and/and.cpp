#include<bits/stdc++.h>
using namespace std;
int a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n-m+1;j++){
			int sum=a[i];
			for(int x=1;x<m;x++){
				sum=sum&a[j+x];
			}
			maxx=max(maxx,sum);
		}
	}
	cout<<maxx;
	return 0;
}
