#include<bits/stdc++.h>
using namespace std;

long long n,m,cnt=0,c=1,sum=0;
long long a[500050];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	if(n>500000 && m>100000000){
		for(int j=n-1;j>0;j--){
			sum=sum+a[n]-a[j];
			c++;
			if(sum>=m || j==1){
				cout<<c<<endl;
				return 0;
			}
		}
	}
	
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>0;j--){
			sum=sum+a[i]-a[j];
			c++;
			if(sum>=m || j==1){
				cnt=max(cnt,c);
				sum=0;
				j=0;
				c=1;
//				cout<<cnt<<endl;
			}
		}
	}
	cout<<cnt;
	return 0;
}
