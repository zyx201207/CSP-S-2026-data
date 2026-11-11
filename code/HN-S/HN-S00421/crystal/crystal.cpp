#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=0,cnt=0;
	int l=1,r=n+1;
	while(l<=r){
		int mid=(l+r)/2;
		if((a[mid]-a[mid-1]>a[mid+1]-a[mid])&&sum<=m){
			a[mid]+=a[mid+1]-a[mid];
			r=mid;
		}
		else{
			a[mid-1]+=a[mid]-a[mid-1];
			l=mid+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				sum+=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
