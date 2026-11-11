#include<bits/stdc++.h>
using namespace std;
long long n,m,min_=1000000000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]<min_)
			min_=a[i];
		}
		cout<<min_;
	}
}
