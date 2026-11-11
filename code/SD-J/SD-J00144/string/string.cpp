#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long val;
	char zim;
}a[N];
long long n;
long long sum[N],ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].zim;
		sum[i]=sum[i-1]+a[i].val;
	}
	int j=n,j1=a[n].val;
	int i=1,i1=a[1].val;
	while(((sum[n]-sum[j-1]-a[j].val+j1)<=sum[n]/2)&&(sum[i]-a[i].val+i1<=sum[n]/2)){
		if(a[i].zim!=a[j].zim){
			ans+=min(i1,j1);
		}
		if(i1>j1){
			i1-=j1;
			j-=1;
			j1=a[j].val;
		}
		else if(j1>i1){
			j1-=i1;
			i+=1;
			i1=a[i].val;
		}
		else{
			i+=1;
			j-=1;
			i1=a[i].val;
			j1=a[j].val;
		}
		if(i==j) break;
	}
	if(sum[n]%2==1){
		if(a[i].zim!=a[j].zim){
			ans+=min(i1,j1);
		}
	}
	cout<<ans;
	return 0;
}

