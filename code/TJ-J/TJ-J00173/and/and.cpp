#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	int a[10003];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n+1;i++){
		if((a[i]&a[i+1])>maxn){
			maxn=a[i]&a[i+1];
		}
	}
	cout<<maxn;
	
	return 0;
}

