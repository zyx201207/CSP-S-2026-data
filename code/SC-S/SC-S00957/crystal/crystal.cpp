#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,cnt=0,maxn=-1,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=a[1];i<=a[n-1];i++){
		if(i>=a[num]){
			num++;
		}
		long long sum=0;
		cnt=0;
		while(cnt<=m&&num-sum>0){
			cnt=cnt+cnt+i-a[num-sum];
			sum++;
		}
	//	cout<<sum<<"\n";
		maxn=max(maxn,sum-1);
	}
	cout<<maxn;
	return 0;
}