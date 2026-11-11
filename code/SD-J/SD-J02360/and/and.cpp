#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long num=0,sum=0,m=0,p=0,e=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0){
		cout<<a[n/2];
	}else{
		cout<<a[n/2+1];
	}
	return 0;
}
