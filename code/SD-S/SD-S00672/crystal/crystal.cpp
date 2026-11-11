#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,l,r,ans=1;
long long m,a[N],qz[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		l=0,r=i+1;
		while (l+1!=r){
			int mid=(l+r)/2;
			if (qz[i]-qz[mid-1]>=(i-mid+1)*a[i]-m)
				r=mid;
			else
				l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
