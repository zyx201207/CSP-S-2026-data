#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,c[N],ans;
long long m,a[N],b[N];
int find(int x,long long s){
	int l=1,r=x,mid;
	long long te=1;
	while(l<=r){
		mid=l+r+1>>1;
		if((b[mid]+te*(a[x]-a[mid])*mid)>=s){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
		if(b[i]>m){
			ans=max(ans,i-find(i,b[i]-m));
		}else{
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}