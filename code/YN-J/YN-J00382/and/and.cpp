#include<bits/stdc++.h>
using namespace std;
//#define long long long long
//#define long long unsigned long long
const long long maxn=2e5+13;
long long a[maxn];
//priority_queue<int> sb;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0){
		cout<<(a[n/2]+a[n/2+1])/2;
	}else{
		cout<<a[(n+1)/2];
	}
	return 0;
}
