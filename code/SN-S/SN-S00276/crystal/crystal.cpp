#include<bits/stdc++.h>
using namespace std;
long long a[10005],sum[20005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=1e9;
	cin>>n>>m;
	int b=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<=num){
				num=a[i];
			}
		}
	while(b==m){
		num+=b;
		for(int i=1;i<=n;i++){
			if(num==a[i]){
				sum[i]++;
			}
		}
		b++;
	}
	int new=0;
	for(int i=1;i<=n;i++){
		new=sum[1];
		if(sum[i]>=new){
			new=sum[i];
		}
	}
	cout<<new;
	return 0;
}
