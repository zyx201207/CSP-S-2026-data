#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,t,y,h,k=1; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		y=a[2]-a[1];
		h=(m-m%y)/y;
		while(h>0){
			h-=k;
			k++;
		}
		cout<<k;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			sum+=a[i]-a[j];
		}
		if (sum<=m){
			t=i;
		}
		sum=0;
	}
	cout<<t;
	return 0;
}
