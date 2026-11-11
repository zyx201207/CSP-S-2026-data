#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n],b[200005];
	int x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i]=min(a[i],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		if(x<b[i])x=b[i];
	}
	cout<<x;
	return 0;
}
