#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005];
long long s(long long x){
	for(long long i=x;i<=n;i++){
		if(a[i]*x+b[i-x]-b[i]<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long down=2,up=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	while(up>down){
		long long middle=(up-down)/2+down;
		if(s(middle)==1){
			down=middle+1;
		}
		else{
			up=middle-1;
		}
	}
	cout<<down-1<<endl;
	return 0;
}
