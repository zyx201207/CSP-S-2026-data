#include<bits/stdc++.h>
using namespace std;
long long n,m,c=1;
const int q=500005;
long long a[q];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long w=a[n/2];
	for(long long i=n/2+1;i<n;i++){
		if(a[i]==w)
			c++;
		else
			break;
	}
	for(long long i=n/2-1;i>=0;i--){
		if(w-a[i]<=m){
			c++;
			m=m-w+a[i];
		}
		else{
			cout<<c;
			return 0;
		}
	}
	cout<<c;
	return 0;
}
