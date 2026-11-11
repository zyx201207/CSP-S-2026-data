#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	bool flag=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i-1)flag=0;
	}
	if(flag==1){
		cout<<n-m;
	}
	else{
		int maxm=0;
		for(int i=1;i<=n;i++){
			maxm=max(maxm,a[i]);
		}
		cout<<maxm;
	}
	return 0;
}
//1 10 11 100
