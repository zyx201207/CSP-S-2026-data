#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[500005];
int b[500005];
int n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(b[i]-b[i-x+1]-(a[i]-a[i-x+1])*(i-x)<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
//		cout<<b[i].val<<endl;
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
} 
