#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	int a[200010];
	cin>>n>>m;
	int v=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]){
				int z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	cout<<a[m];
} 
