#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=a[n];
	int t=int(floor(log(2,a[n]))
	for(int i=n-1;i>=n+1-m;i--){
		if(floor(log(2,a[i]))!=t) break;
		if(i==n-1-m){
			for(int i=n;i>=n+1-m;i--){
				f=f&i;			 
			}
			cout<<f;
		}
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
