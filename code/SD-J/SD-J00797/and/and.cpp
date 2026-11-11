#include<bits/stdc++.h>
using namespace std;
int n,k,a[400005]={0},cnt,maxans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,greater<int>());
//	for(int i=1;i<=n;i++){
//		cout<<a[i];
//	} 
	for(int l=1;l<=n;l++){
		cnt=a[l];
		
		for(int r=0;r<k;r++){
			cnt&=a[l+r];
		}
		//cout<<cnt;
		maxans=max(cnt,maxans);
	}
	cout<<maxans;
	return 0;
}
