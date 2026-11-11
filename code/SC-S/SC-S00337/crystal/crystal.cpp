#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
long long check(long long st,long long x){
	return st*(x-1)*(x)/2;
}
int main(){
//	freopen(“能量水晶.里面”，“读入”，“学生输入”);
//	freopen(“能量水晶.里面”，“写出”，“学生输出”);
//  为什么不用中文呢？
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int t=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			t=0;
		}
	}
	sort(a+1,a+1+n);
	long long pd=a[2]-a[1];
	int tt=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=pd){
			tt=0;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
	}
	if(t==1){
		long long l=1,r=m,ans=0;
		int o=0;
		while(l<=r){
			long long mid=l+(r-l)/2;
			if((mid-1)*mid/2<m){
				ans=mid;
				l=mid+1;
			}
			else if((mid-1)*mid/2>m){
				r=mid-1;
			}
			else{
				o=1;
				cout<<ans+1;
				break;
			}
		}
		if(o==0){
			cout<<ans;
		}
		return 0;
	}
	if(tt==1){
		long long l=1,r=m,ans=0;
		int o=0;
		while(l<=r){
			long long mid=l+(r-l)/2;
			if(check(a[2]-a[1],mid)<m){
				ans=mid;
				l=mid+1;
			}
			else if(check(a[2]-a[1],mid)>m){
				r=mid-1;
			}
			else{
				o=1;
				cout<<ans+1;
				break;
			}
		}
		if(o==0){
			cout<<ans;
		}
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1){
				if(s[i]<=m){
					ans=max(ans,(long long)i);
				}
				else{
					break;
				}
			}
			else{
				int x=a[i]-a[j-1];
				if(s[i]-x<=m){
					ans=max(ans,(long long)(i-j+1));
				}
				else{
					break;
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
 