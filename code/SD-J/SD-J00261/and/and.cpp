#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,maxx=0,ai;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++,ai++){
		cin>>a[ai];
		for(int j=0;j<m;j++){
			if(a[i]>a[j]) {
				a[j]=a[i];
				ai--;
			}
		}
	}
	long long ans=a[1];
	for(int i=2;i<m;i++){
		ans=(ans&a[i]);
	}
	maxx=max(ans,maxx);
	cout<<maxx;
	return 0;
}
