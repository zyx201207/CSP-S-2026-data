#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int chai(long long n){
	int sum=0;
	while(n){
		if(n%2==1){
			sum++;
		}
		n/=2;
	}
	return sum;
}
bool abc(long long a,long long b){
	return a>=b&&chai(a)>=chai(b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,abc);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}