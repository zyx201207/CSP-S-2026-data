#include<bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rdm(time(0));

const int N=5e5+5;

int pre[N],a[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1;
	int l,r,mid,sum;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i]; 
		l=1,r=i,sum=i;
		while(l<=r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
				sum=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-sum+1);
	}
	cout<<ans;
	return 0;
}
/*

freopen("crystal.in","w",stdin);
freopen("crystal.out","r",stdout);
freopen("crystal.in",'r',stdout);
froepen("crystal.in","r",stdout);
froepen("crystal.out","w",stdout);
freopen("crystal.out",'w',stdout);
int mian()
by luogu:1033244

T1水 100pts 

T2+T3 打不出来，思考3h没成果 8+24

T4 15pts

作为初中生最后一次CSP

拉完了 
*/
