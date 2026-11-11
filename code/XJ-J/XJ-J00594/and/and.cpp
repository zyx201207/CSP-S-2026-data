#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxsum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int sum=a[i] and a[j];
			maxsum=max(maxsum,sum);
		}
	}
	cout<<maxsum;
	return 0;
}
