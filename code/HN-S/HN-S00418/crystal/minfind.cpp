#include<bits/stdc++.h>
using namespace std;
int a[7]={0,1,2,3,4,5,6};
bool check(int x){
	return a[x]>3;
}
signed main(){
	int l=1,r=6,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
//			cout<<mid<<'\n';
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans;
	
	
	
	return 0;
}
