#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
long long p=-1;
long long cost[N];
int l=1,r=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		r=i;
		cost[i]=cost[i-1]+(long long)(i-1)*(a[i]-a[i-1]);
		if(r-l+1<p){
			continue;
		}
		if(cost[i]-(long long)cost[l-1]-(long long)(l-1)*(a[i]-a[l-1])<=m){
			p=max((long long)(r-l+1),p);
		}else{
			int cur_l=l,cur_r=r,mid;
			while(cur_l<cur_r){
				mid=(cur_l+cur_r)>>1;
				if(cost[i]-(long long)cost[mid-1]-(long long)(mid-1)*(a[i]-a[mid-1])<=m){
					cur_r=mid;
				}else{
					cur_l=mid+1;
				}
			}l=cur_r;
			p=max((long long)(r-l+1),p);
		}
	}
	cout<<p;
	return 0;
} 