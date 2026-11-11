#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	bool qwea=true;
	bool qweb=true;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		if(a[i]!=i) qwea=false;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) qweb=false;
		}
	}
	
	if(qwea){
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if((mid*(mid+1)/2)<=m) l=mid;
			else r=mid-1;
		}
		cout<<l+1;
		return 0;
	}else if(qweb){
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if((mid*(mid+1)*(a[2]-a[1])/2)<=m) l=mid;
			else r=mid-1;
		}
		cout<<l+1;
		return 0;
	}
	
	int ans=1;
	for(int i=2;i<=n;i++){
		int temp=1;
		int num=0;
		int cnt=0;
		for(int l=i;l>=1; ){
			num+=a[l]-a[l-1];
			if(cnt+num>m){
				break;
			}else{
				cnt+=num;
				l--;
				temp++;
			}
		}
		ans=max(ans,temp);
	}
	
	cout<<ans;
	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 13
2 4 6 8 10 12

*/
