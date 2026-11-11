#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll sum[N]; 
int max_cnt=1;
/*5 5
1 2 4 8 9*/
bool check(int mid,int x){
	//cout<<"x="<<x<<" mid="<<mid<<"ans="<<a[x+1]*(x-mid+1)-(sum[x]-sum[mid-1])<<endl;
	if(a[x+1]*(x-mid+1)-(sum[x]-sum[mid-1])<=m){
		//cout<<"yes"<<endl;
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//sum[i]=a[i]+sum[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		//ll m_=m;
		int x=i-1;
		int l=1,r=i-1;
		//cout<<"i="<<i<<endl;
		int mid=(l+r)>>1;
		while(l<r){
			mid=(l+r)>>1;
			//cout<<"l="<<l<<"r="<<r<<"mid="<<mid<<endl;
			if(check(mid,x)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		cnt=i-l+1;
		max_cnt=max(max_cnt,cnt);
	}
	cout<<max_cnt<<endl;
	return 0;
}

