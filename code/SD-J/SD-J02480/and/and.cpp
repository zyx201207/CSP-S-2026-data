#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	/*for(int i=n;i>=1;i--){
		cout<<a[i]<<" ";
	}*/
	int x=a[n],j=1;
	for(int i=n-1;j<m;i--){
		if(j==m){
			break;
		}
		if(a[i]!=a[i+1]){
			x=x&a[i];
			//cout<<a[i]<<" "<<x<<"\n";
			j++;
		}
		
	}
	cout<<x;
	return 0;
}/*
5 3
31 3 1 15 7
*/
