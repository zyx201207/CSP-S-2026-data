#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=0,minn=1000000;
	long long andn[100000];
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>andn[i];
	}
	for(long long i=0;i<n;i++){
		maxn=max(andn[i],maxn);
	}
	cout<<maxn;
	return 0;
}
