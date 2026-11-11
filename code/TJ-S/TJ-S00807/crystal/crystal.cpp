#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0},b[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long m,n,pd1=0,pd2=0,pd3=0;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			pd1++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(i>1&&b[i]==b[i-1]){
			pd2++;
		}
		if(i>1&&b[i]==0){
			pd3++;
		}
	}
	if(pd1==n){
		long long ans=m,tot=0;
		for(int i=1;i<=m;i++){
			if(ans-i>=0){
				ans-=i;
				tot++;
			}
			else{
				cout<<tot;
				return 0;
			}
		}
	}
	else if(pd2==n-1){
		long long aaa=a[2]-a[1];
		long long ans=m,tot=0;
		for(int i=aaa;i<=m;i+=aaa){
			if(ans-i>=0){
				ans-=i;
				tot++;
			}
			else{
				cout<<tot;
				return 0;
			}
		}
	}
	else if(pd3==n-1){
		cout<<n;
		return 0;
	}
	else{ 
		long long ans=m,tot=1;
		for(int k=1;k<=m;k++){
			for(int i=1;i<=n;i++){
				if(ans-(b[i])*tot>=0){
					ans-=(b[i])*tot;
					tot++;
					
				}
				else{
					cout<<tot;
					return 0;
				}
			}
		}
	}
	return 0;
}
