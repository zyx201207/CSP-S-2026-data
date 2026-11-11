#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];

int n;
long long m;
bool check(int pre){//pre:前pre个数一样 
	long long ave=a[pre];
	long long tmp=ave*pre*1ll-sum[pre];
	if(tmp<=m) return 1;
	//if(pre==315275) cout<<sum<<"\n";
	return 0;
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
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n,flag;
	int mid;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)){
			flag=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	
	cout<<flag;
	return 0;
} 