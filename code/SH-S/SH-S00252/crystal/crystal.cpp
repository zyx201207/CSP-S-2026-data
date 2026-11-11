//没有优化!!! 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool A=true,B=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=false;
		}
		if(i>=2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				B=false;
			}
		}
	}
	if(A){
		for(int i=max(int(sqrt(2*m))-1,0);i<n;i++){
			if(i*(i-1)/2.0>m){
				cout<<i-1<<endl;
				return 0;
			}
		}
	}
	else if(B){
		int d=a[1]-a[0];
		for(int i=max(int(sqrt(2*m/d+1))-1,0);i<n;i++){
			if(i*(i-1)*d/2.0>m){
				cout<<i-1<<endl;
				return 0;
			}
		}
	}
	
	else{
		sort(a,a+n);
	int ans=1;
	for(int i=1;i<n;i++){
		int tmp=0;
		for(int j=i-1;j>=0;j--){
			tmp+=(a[i]-a[j]);
			if(tmp>m){
				ans=max(ans,i-j);
				break;
			}
			else if(j==0&&tmp<=m){
				ans=max(ans,i+1);
			}
		}
	}cout<<ans;
	} 
	
	return 0;
}
