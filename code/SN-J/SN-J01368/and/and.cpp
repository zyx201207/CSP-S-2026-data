#include<bits/stdc++.h>
using namespace std;	
int a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(max1<a[i]){
			max1=a[i];
		}
	}
	cout<<max1;
	return 0;
}
