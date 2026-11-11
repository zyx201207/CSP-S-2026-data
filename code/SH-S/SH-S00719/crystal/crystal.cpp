#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,cnt,a[N];
bool check(ll mid){
	bool f=0;
	for(int i=n;i>=1;i--){
		ll s=0;
		if(i<mid){
			break;
		}
		for(int j=i-1;j>=i-mid+1;j--){
			s+=a[i]-a[j];
		}
		if(s<=m){
			f=1;
		}
	}
	if(!f){
		return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool f=1,f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=0;
		}
		if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f1=0;
		}
	}
	if(f){
		ll s=0,sum=0;
		for(int i=1;i<=n;i++){
			sum++;
			s+=i;
			if(s>m){
				break;
			}
		}
		cout<<sum;
		return 0;
	}
	if(f1){
		ll s=0,sum=0;
		ll sub=a[2]-a[1];
		for(int i=1;i<=n;i++){
			sum++;
			s+=sub*i;
			if(s>m){
				break;
			}
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n);
	ll l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
/*
5 5
1 2 4 8 9

3



5 8
-3 -1 2 2 7

4
*/
