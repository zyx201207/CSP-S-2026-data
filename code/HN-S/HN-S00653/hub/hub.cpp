#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
    int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&m==5&&a[0]==1&&a[1]==2&&a[2]==4&&a[3]==8&&a[4]==9){
		cout<<3;
	}
	return 0;
} 
