#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],q[N],Ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)/2;
			int tar=(i-mid)*a[i];
			if(tar-(q[i-1]-q[mid-1])<=m)r=mid-1,ans=mid;
			else l=mid+1;
		}
		Ans=max(Ans,i-ans+1);
	}
	cout<<Ans;
	return 0;
}
/*
先排个序，然后枚举哪一个数作为基准值，让他前面的数尽可能变成他
显然这个可以二分。
时间复杂度 O(n log n) 
14:47 AC
*/
/*
guan zhu luogu uid 1283951 xie xie miao
rp++rp++rp++
//freopen
froepen
"crystal.ans"
'r'
sdtout
iakioi
int mian()
reutrn 0;
"crystal1.out"
*/
