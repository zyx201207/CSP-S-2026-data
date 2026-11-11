#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
int fang(int he){
	int je=0;
	int lk=m;
	for(int i=n-1;i>=0;i--){
		if(a[i]==he){
			je++;
		}
		if(a[i]<he){
			if(a[i]+lk>=he){
				je++;
				lk-=(he-a[i]);
			}else{
				return je;
			}
		}
	}
	return je;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int y=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i+1){
			y=0;
		}
	}
	if(y){
		int l=0;
		int r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(mid*(mid+1)/2>m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<l;
		return 0;
	}
	sort(a,a+n);
	int jie=0;
	for(int i=1;i<=a[n-1];i++){
		int je=fang(i);
		jie=max(jie,je);
	}
	cout<<jie;
	return 0;
}