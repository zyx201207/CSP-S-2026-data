/*
我好像可以贪出来？ 
只需要求出abs(x-y)最大且f1[y]-f1[x]<=m的x,y 
f1还是单调递增
 所以可以简化为给定一个数组
 求在这个数组内最多可以连续取多少个数且和<=m 
 最朴素的想法->双层循环枚举 
 虽然会TLE 但是这只是保分 
 好了暴力分拿到了
 接下来尝试双指针或二分 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
bool A=true,B=true;
int n,m,ans,a[N];
int f[N];//f[i]=a[i+1]-a[i];
int f1[N];// 
int f2[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
//  cout<<(sizeof f+sizeof f1+sizeof f2)/1024/1024;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	 
//		cout<<a[i]<<" "<<i<<"\n";
	}
	
	sort(a+1,a+1+n);
	 int cm=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=i){
		A=false;
//		cout<<a[i]<<" "<<i<<"\n";
		}
		if(a[i]-a[i-1]==cm)B=false;
	}
 //       cout<<A<<" "<<B<<"\n";
	if(A){
		for(int i=1;i<=n;i++){
			if((i*(i-1))/2<=m){
				ans=i;
			}else 
			{
			    break;
			}
		}
		cout<<ans;return 0;
	}else if(B){
		for(int i=1;i<=n;i++){
			if((i*(i+1))/2*cm>m){
				ans=i-1;
				break;
			}
		}
		cout<<ans;return 0;
	}
	if(a[1]!=1)A=false;
	for(int i=1;i<n;i++){
	     f[i]=a[i+1]-a[i];
	     f1[i]=f1[i-1]+f[i];
	     f2[i]=f2[i-1]+f1[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			if(i==2&&j==3)cout<<j<<" "<<i<<" "<<(j-i)*f1[j-1]-f2[j-2]+f2[i-2>0?i-2:0]<<"\n";
            if((j-i)*f1[j-1]-f2[j-2]+f2[i-2>0?i-2:0]<=m){
  //          	cout<<j<<" "<<i<<" "<<(j-i)*f1[j-1]-f2[j-2]+f2[i-2>0?i-2:0]<<"\n";
			ans=max(ans,j-i+1);
			}
		}
	} 	
//	  int l=1,r=n;
	  
//	 for(int i=1;i<=n;i++){
//	 	int l=i,rmax=0;
//	 	while(T--){
//	 		  int mid=(i+r)/2;
//	 		if((mid-i)*f1[mid-1]-f2[mid-2]+f2[i-2>0?i-2:0]>m)
//			{
//	 		    r=mid-1;
//			}else{
//				r=mid+1;
//				rmax=max(rmax,r);
//				ans=max(ans,mid-l+1);
//			}
//		 }
//	 }
cout<<ans;
}