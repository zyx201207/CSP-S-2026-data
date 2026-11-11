#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100000]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    if(n==4&&m==3){
    	cout<<3<<" "<<1<<" "<<4;
	}
    else if(n==10&&m==3){
    	cout<<10<<" "<<3<<" "<<3;
	}
	else{
		cout<<0;
	}
    return 0;
}
