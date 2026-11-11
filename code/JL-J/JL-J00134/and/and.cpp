#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005]
int main(){
	fropen("and.in","r",stdin);
	fropen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=0,x=0;
	for(int i=1;i<=n;i++){
		x=a[i]%a[i+1];
		if(x>a[i+1]%a[i+2]){
			max=x;
		}
	}
	cout<<max;
	return 0;
}

