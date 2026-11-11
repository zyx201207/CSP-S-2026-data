//SN-S00492  刘泽   西安铁一中滨河学校 
#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long ans=-1;
long long a[500001];
long long cha[500001];

int findans(int num,long long maxn){
	int daan=0;
	int sum=0;
	sum=cha[num];
	while(maxn>0){
		if(maxn>=sum){
			maxn-=sum;
			daan++;
			num--;
			sum+=cha[num];
		}
		if(num==1)return (daan+1);
		if(maxn<sum)break;
	}
	return (daan+1);
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
		cha[i]=a[i]-a[i-1];
	}
	for(int i=n;i>1;i--){
		long long now=findans(i,m);
		ans=max(ans,now);	
	}
	cout<<ans;
	return 0;
}

