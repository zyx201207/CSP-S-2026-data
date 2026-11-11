#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	int a[n];
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			a[i]=-a[i];
		}
	}
	int a1,shu=0;
	for(i=1;i<=m;i++){
		if((a[i]+1)==a[i+1]){
			shu+=1;
			a[i]=a[i+1];
			a1=a[i]+a[i+1];
		}
		else if(a1==a[i]){
			a[i]+=a[i+1];
			a1+=a[i];
			shu+=1;
		}
	}
	cout<<shu;
	return 0;
}
