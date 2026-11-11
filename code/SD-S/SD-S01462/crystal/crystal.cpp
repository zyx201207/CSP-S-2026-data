#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],h,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],h+=a[i];
	h/=n;
	sort(a+1,a+1+n);
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>h) r=mid-1; 
		else l=mid+1;
	}
//	cout<<l<<' '<<r<<' '<<mid<<' '<<h; //l
	int z1=l-1,z2=l+1;
	while(m){
		if(a[z1]-a[l]>a[z2]-a[l]){
			if(m>abs(a[z2]-l)) ans++,z2++,m-=abs(a[z2]-l);
			else break;
		}
		else{
			if(m>a[z1]-l) ans++,z1--,m-=abs(a[z1]-l);
			else break;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
Oct31==Dec25?
*/
