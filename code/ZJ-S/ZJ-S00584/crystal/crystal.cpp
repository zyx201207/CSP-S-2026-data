#include<bits/stdc++.h>//T1->crystal
using namespace std;
const int N=500010;
long long n,m,a[N],sum[N];
bool check(int lenth){
	for(int i=1;i+lenth-1<=n;i++){
		if(sum[i+lenth-1]-sum[i-1]+m>=a[i+lenth-1]*lenth){
			//cout<<lenth<<' '<<i<<endl;
			return 1;
		}
	}return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	//二分长度，0<len<=n
	int l=1,r=n;
	while(l<r){
		int len=(l+r+1)/2;
		if(check(len)){
			l=len;
		}else r=len-1;
	}cout<<l;
	return 0;
}
