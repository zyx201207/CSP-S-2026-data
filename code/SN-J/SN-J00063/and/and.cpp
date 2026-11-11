#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=0;i<n;i++){
		sort(a,a+n);
		if(a[i+1]==0){
			break;
		}
		if(a[i]==a[i+1]){
			a[i+1]=0;
		}
	}
	cout<<a[n/2];
	return 0;
}
