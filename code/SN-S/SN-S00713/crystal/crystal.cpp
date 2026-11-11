#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;	
	long long mid=0;	
	while(l<r){
		mid=(l+r+1)/2;
		long long num=0;
		for(int i=1;i<mid;i++){
			num+=a[mid]-a[i];
		}
		if(num>m){
			r=mid-1;
		}else{
			l=mid;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[l]){
			cout<<i-1; 
			return 0;
		}
	}
	return 0;
}
