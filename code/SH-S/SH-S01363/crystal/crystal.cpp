#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[250000];
int b[250000];
int sum=-1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	//if(m==0){
	//	int ans=-1;
	//	for(int i=0;i<n;i++){
	//		cont[a[i]+100000]++;
	//		ans=max(ans,cont[a[i]+100000]);
	//	}
	//	cout<<ans;
	//	return 0;
	//}
	sort(a,a+n);
	for(int i=1; i<n; i++) {
		b[i]=a[i]-a[i-1];
	}
	for(int l=0; l<n; l++) {
		int c[250000],d[250000];
		int num;
		c[l]=d[l]=0;
		for(int i=l+1; i<n; i++) {
			c[i]=c[i-1]+b[i];
			d[i]=d[i-1]+c[i];
			num=c[i]*(i-l)-d[i-1];
			if(num<=m){
				sum=max(sum,i-l+1);
			}else{
				break;
			}
		}
	}
	//for(int i=0;i<n;i++){
	//	cout<<a[i]<<" ";
	//}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
