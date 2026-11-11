#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500006];
long long num;
long long sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[1];
	}
	else if(m==n){
		num=a[1]&a[2];
		for(int i=32;i<=n;i++){
			num=num&a[i];
		}
		cout<<num;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j){
					continue;
				}
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
