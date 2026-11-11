#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],l,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) a[i]-=a[1];
	a[1]=0;
	for(int i=1;i<=n;i++){
		a[i]=m-a[i];
		if(a[i]>0) l=i;
	}
	for(int i=1;i<=l;i++) sum+=a[i];
	while(sum>m){
		int t=0;
		for(int i=1;i<=n;i++){
			if(i!=l){
				a[i]-=a[l];
				if(a[i]>0) t=i;
			}
		}
		a[l]=0; l=t; sum=0;
		for(int i=1;i<=l;i++) sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=0) l=i;
	}
	cout<<l;
	return 0;
}
