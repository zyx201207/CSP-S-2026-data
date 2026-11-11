#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N];
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]&a[i]>sum && j!=i) sum=a[j]&a[i];
		} 
	}
	cout<<sum;
	return 0;
}
