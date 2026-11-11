#include<bits/stdc++.h>
const int N=5e5+5;
using namespace std;
long long n,m,ans=-1;
long long a[N],del[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	long long del=a[2]-a[1];
	bool f=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=del){
			f=false;
			break;
		}
	}
	if(f){
		int i=1;
		for(;i<=n;i++){
			long long average=i*(i+1);
			if(del*average>m*2){
				break;
			} 
		}
		cout<<i;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long t=i,st=m;
		while(t>=1){
			st-=(a[i]-a[t]);
			if(st<0)break;
			t--;
		}
		ans=max(ans,i-t);
	}
	cout<<ans;
	return 0;
}

