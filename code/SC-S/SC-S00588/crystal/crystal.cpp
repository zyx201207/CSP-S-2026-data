#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[500010],ans=-1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int bj=0,dc=a[2]-a[1],bj1=0;
	for(long long i=1;i<=n;i++){
		if(a[i]!=i){
			bj=1;
			break;
		}
	}
	for(long long i=1;i<n;i++){
		if(a[i]+dc!=a[i+1]){
			bj1=1;
			break;
		}
	}
	if(bj==0){
		long long top=0,qq=0;
		while(m-top>=0){
			m-=top;
			top++;
			qq++;
		}
		cout<<qq;
		return 0;
	}
	if(bj1==0){
		long long top=0,qq=0;
		while(m-dc*top>=0){
			m-=top*dc;
			top++;
			qq++;
		}
		cout<<qq;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long ts=m,top=i,ans1=0;
		while(ts-(a[i]-a[top])>=0&&top){
			ts=ts-(a[i]-a[top]);
			top--;
			ans1++;
		}
		if(ans<ans1){
			ans=ans1;
		}
	}
	cout<<ans;
	return 0;
}
