#include <iostream>
#include <algorithm>
using namespace std;
const int N=5e5+5;
long long a[N];
long long b[N];
long long ans=0;
int n,m;
bool judge(int x,int i){
	return (i-x+1)*a[i]-(b[i]-b[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l!=r){
			int mid=(l+r)>>1;
			if(judge(mid,i)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,(long long)(i-r+1));
		//cout<<i<<' '<<r<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
/*
1 1 2 4 1
1 2 3 4 5
(i-mid+1)*a[i]-(b[i]-b[mid-1])

*/