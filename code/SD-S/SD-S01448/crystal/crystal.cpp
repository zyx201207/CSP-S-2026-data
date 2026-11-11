#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],s[N];
int l,r,ans,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-ans+1);
	} 
	cout<<maxx<<'\n';
	return 0;
}
//文件输入输出
//数组越界，头文件，整数溢出，副行为顺序 
//不要写scanf，string要开空间（reverse） 
//开long long 
