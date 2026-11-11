#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	bool x=true;
	cin>>n>>m;
	int a[MAXN],d[MAXN],ans=1,sum,tg=1;
	d[0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		d[i]=a[i]-a[i-1];
		if(i>2&&d[i-1]!=d[i]){
			x=false;
		}
	}
	if(!x){
		goto label3;
	}
	for(int i=1;i<n;i++){
		label2:
		sum=0;
		for(int j=ans;j>0;j--){
			sum+=(j-1)*d[i-ans+j];
			if(sum>m){
				goto label1;
			}
		}
		if(ans==i+1){
			tg=0;
		}
		if(ans<=i){
			ans++;
			tg=1;
			goto label2;
		}
		
		label1:
		sum=0;
	}
	cout<<ans-tg;
	return 0;
	label3:
	cout<<floor(0.5*(1+sqrt(1+8.0*m/(d[2]))));
	return 0;
	
}
