#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],b[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2,t=1,s=0;
		for(int i=2;i<=n;i++){
			s+=(a[i]-a[i-1])*t; t++;
			if(i>mid){
				s-=a[i]-a[i-mid]; t--;
			}
			if(i>=mid&&s<=m){
				t=-1; break;
			}
		}
		if(t==-1) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}