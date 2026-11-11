#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,max_num;
long long m;
long long a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
		int ans=0,l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(pre[i-1]-pre[mid-1])<=m){
				ans=i-mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		max_num=max(max_num,ans);
	}
	cout<<max_num+1;
	return 0;
}
