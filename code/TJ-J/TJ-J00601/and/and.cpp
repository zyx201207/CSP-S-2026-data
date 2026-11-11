#include<bits/stdc++.h> 
using namespace std;
int n,m,a[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout <<a[m-1]<<' ';
		break;
	}
	return 0;
}

