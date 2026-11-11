#include<bits/stdc++.h>
using namespace std;

long long n,m,a[510000],r=1,k=1,i;
int main(){
	freopen(":crystal.in","r",stdin);
	freopen(":crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	while(m>=0&&k<n){
		if(k*(a[k]-a[k-1])<=m){
			++r;
			m-=k*(a[k]-a[k-1]);
			k++;
		}
		else break;
	}
	cout<<r;
	return 0;
}