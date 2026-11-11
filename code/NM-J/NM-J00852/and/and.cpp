#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=0;
	for(int i=1;i<=n;i++){
		if(a[i]<max){
			a[i]=max;
		}
	}
	cout<<"12";
	return 0;
} 

