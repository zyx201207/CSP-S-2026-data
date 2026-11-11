#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n;
int m;
int ans;
int a[N]; 
int check(int x,int y){
	int sum=0;
	for(int i=x;i<=y;i++){
		sum+=abs(a[y]-a[i]);
	}
	return sum;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid;
		int cnt=0;
//		cout<<i<<'\n';;
		while(l<r){
			mid=(l+r)>>1;
			int abab=check(mid,i);
//			cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid,i)<<'\n';
			if(abab>m){
				l=mid+1;
			}else{
				if(abab<=m){
					cnt=max(cnt,r-l+1);
				}
				r=mid-1;
			}
		}
//		ans+=a[n]-a[i];
//			cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid,i)<<'\n';
//		cout<<mid<<'\n';
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
//TM结束半小时才说T2 
//ccf 的妈妈在天旋转！！！！！！！！！！！！！！！ 
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf
//f*ck ccf 
//我不会啊╮(╯﹏╰)╭
//oh sh*t!!! 
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
//我是废物！！！
 
