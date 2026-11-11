#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i+1;j<=n;j++){
			int sum=a[i];
			
			for(int k=0;k<m-1;k++){
				sum=sum&a[j+k];
			}
			maxn=max(maxn,sum);
			
		}
	}
	cout<<maxn;
	return 0;
}
