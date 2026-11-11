#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005];
int n,m,maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		b[i]=a[i]&a[i-1];
		if(b[i]>=b[i-1]){
			maxx=b[i];
		}
	}
	cout<<maxx;
	return 0;
}

