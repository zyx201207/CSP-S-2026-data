#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct qwer{
	long long sum;
	char s;
	long long l,r;
}a[200050];
long long L=0;
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].sum>>a[i].s;
		L+=a[i].sum;
	}
	if(L%2==1){
		long long mid=(1+L)>>1;
		long long k=0;
		for(int i=1;i<=n;++i){
			k+=a[i].sum;
			if(k>=mid){
				--a[i].sum;
				break;
			}
		}
		L--;
	}
	for(int i=1;i<=n;++i){
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+a[i].sum-1;
	}
	long long mid=(1+L)>>1;
	long long same=0;
	long long end=n;
	for(int i=1;i<=n;++i){
		long long l=a[i].l;
		long long r=a[i].r;
		if(l>mid){
			break;
		}
		if(r>mid){
			r=mid;
		}
		long long rr=L-(l-1);
		long long ll=L-(l-1)-a[i].sum+1;
		if(rr<=mid){
			break;
		}
		if(ll<=mid){
			ll=mid+1;
		}
		for(int j=end;j>=1;--j){
			if(a[j].r<ll){
				end=j+1;
				break;
			}
			if((a[j].l>=ll && a[j].r<=rr) || (a[j].l>=ll && a[j].l<=rr) || (a[j].r>=ll && a[j].l<=rr)){
				if(a[j].s!=a[i].s){
					long long fugai=(min(a[j].r,rr)-max(a[j].l,ll)+1);
					same+=fugai;
				}
			}
		}
	}
	cout<<same<<endl;
	return 0;
} 
/*
3
2 a
2 b
1 c


2
2 a
3 a


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

6
1 a
1 b
1 c
1 d
1 r
1 g
1 h
*/
