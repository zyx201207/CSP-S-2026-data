/*
可能会AC:1~18
可能会TLE:19,20
1~9:n^2的枚举
10~12:改为枚举合并时的值
13~15:特殊性质A 
16~18:特殊性质B
19,20:TLE
突然想起来上午普及组时一道题全抓的特殊性质和特殊数据范围:) 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
bool A=1,B=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=1){
			A=0;
		}
		if(i!=2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				B=0;
			}
		}
	}
	if(A){
		//寻找最大的n使得n*(n-1)/2<=m
		int l=0,r=n,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid-1)/2<=m){
				l=mid+1;
				if((mid+1)*mid/2>m){
					ans=mid;
					break;
				}
			}else{
				r=mid-1;
			}
		}
		cout<<min(ans,n);
	}else if(B){
		//寻找最大的n使得同上,只左侧*c 
		int c=a[2]-a[1];
		int l=0,r=n,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			if(c*mid*(mid-1)/2<=m){
				l=mid+1;
				if(c*(mid+1)*mid/2>m){
					ans=mid;
					break;
				}
			}else{
				r=mid-1;
			}
		}
		cout<<min(ans,n);
	}else if(a[n]-a[1]<n){
		//改为枚举期望的合并用途数值 
		int mxans=0;
		for(int i=a[1];i<=a[n];i++){
			int tm=m,tans=0;
			int l=0,r=n,mid,ans;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[mid]<=i){
					l=mid+1;
					if(a[mid+1]>i){
						ans=mid;
						break;
					}
				}else{
					r=mid-1;
				}
			}
			for(int j=ans;j>=1;j--){
				if(tm>=i-a[j]){
					tans++;
					tm-=i-a[j];
				}
			}
			mxans=max(mxans,tans);
		}
		cout<<mxans;
	}else{
		int mxans=0;
		for(int i=1;i<=n;i++){
			int tans=1;//必然有自己是可选的
			int tm=m;
			for(int j=i-1;j>=1;j--){
				//不考虑自己
				if(tm>=a[i]-a[j]){
					tans++;
					tm-=a[i]-a[j];
				}
			} 
			mxans=max(mxans,tans);
		}
		cout<<mxans;
	}
	return 0;
}
