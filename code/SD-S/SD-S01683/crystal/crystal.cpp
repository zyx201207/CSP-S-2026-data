#include<bits/stdc++.h>
using namespace std;
int a[500005];
int xd(int l,int r,int x){//在区间[l,r]中不大于x的最大的那个数的下标没有返回0 
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>x){
			r=mid-1;
		}else{
			ans=mid;
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int x=a[1];//x预定为答案 
	int ans=0;//最后的结果 
	bool ok=1;
	while(ok){
	    int xans=0;//以x为基准时可以使多少个数字变成一样的x
		int it=xd(1,n,x);
		for(int i=it;i>=1;i--){
			if(m>=x-a[i]){
				m-=(x-a[i]);
				a[i]=x;
				xans++;
			}else{
				ok=0;
			}
		}
		ans=max(ans,xans);
		x++;
	}
	cout<<ans;
	return 0;
}
