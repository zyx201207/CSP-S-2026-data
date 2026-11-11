#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n,m;
ll a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1) cout<<a[1];
	else if(m==n){
		ll sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(m==2){
		ll mmax=-1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ll o=a[i]&a[j];
				mmax=max(mmax,o);
			}
		}
		cout<<mmax;
	}else{
		ll sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	return 0;
}
