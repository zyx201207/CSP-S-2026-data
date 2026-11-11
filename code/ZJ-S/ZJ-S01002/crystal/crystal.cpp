#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num,j,p[500005],l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>5000){
		j=n;
		num=n*(n-1)/2*(a[2]-a[1]);
		while(num>=m){
			j--;
			num-=j*(a[2]-a[1]);
		}
		cout<<j;
	}else{
		j=n;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			num+=a[n]-a[i];
			p[i]=a[n]-a[i];
			cout<<num<<" "<<p[i]<<endl;
		}
		while(num>m){
			j--;
			num-=j*p[j];
			for(int i=1;i<j;i++)p[i]-=p[j];
		}
		cout<<j;
	}
}
