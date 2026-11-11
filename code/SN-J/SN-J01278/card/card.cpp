#include<bits/stdc++.h>
using namespace std;
long long a[300005];
long long q[300005];
long long c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long b=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(b>0){
	
	for(int i=1;i<=n;i++){
		q[1]=a[i];
		if(q[1]==a[i+1]){
			c[i]=a[i+1];
		}
	}
}
	
	return 0;
} 
