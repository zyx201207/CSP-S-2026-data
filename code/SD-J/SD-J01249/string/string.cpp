#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int n;
int m=0;
struct FJ{
	int l,r;
	char ch;
};
FJ a[200200];
int ans=0;
int f(int l,int r,int k){
	int mid=(l+r)/2+1;
	if (l==r){
		return l;
	}
	if (a[mid].l<=k){
		return f(mid,r,k);
	}
	else {
		return f(l,mid-1,k);
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		int k;
		cin>>k>>a[i].ch;
		a[i].l=m+1;
		m+=k;
		a[i].r=m;
	}
	int mid=m/2;
	int mid1=0;
	for (int i=1;i<=n;i++){
		if (mid>=a[i].l && mid<=a[i].r){
			mid1=i;
			if (mid!=a[i].r){
				n++;
				for (int j=n;j>i;j--){
					a[j].l=a[j-1].l;
					a[j].r=a[j-1].r;
					a[j].ch=a[j-1].ch;
				}
				a[i+1].l=mid+1;
				a[i+1].r=a[i].r;
				a[i+1].ch=a[i].ch;
				a[i].r=mid;
			}
			break;
		}
	}
	for (int i=1;i<=mid1;i++){
		int rr=f(mid1+1,n,m-a[i].l+1);
		int ll=f(mid1+1,n,m-a[i].r+1);
		for (int j=ll;j<=rr;j++){
			int lef=max(a[j].l,m-a[i].r+1);
			int righ=min(a[j].r,m-a[i].l+1);
			if (a[i].ch!=a[j].ch){
				ans+=righ-lef+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
