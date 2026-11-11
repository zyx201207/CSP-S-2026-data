#include<bits/stdc++.h>
using namespace std;
int a[100010];

int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	long long n;
	long long m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxn){
				maxn=a[i]&a[j];
			}
		}
	}
	cout<<maxn;
	return 0;
}
