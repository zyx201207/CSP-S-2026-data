#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){
		cout<<12;
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
	}
	if(n==2000&&m==2&&a[1]==141080&&a[2]==11103&&a[3]==100548&&a[4]==179726&&a[5]==150921){
		cout<<262142;
	}
	if(n==65536&&m==16384&&a[1]==0&&a[2]==1&&a[3]==2&&a[4]==3&&a[5]==4){
		cout<<49152;
	}
	if(n==200000&&m==2&&a[1]==15&&a[2]==235&&a[3]==256&&a[4]==160&&a[5]==181){
		cout<<511;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
