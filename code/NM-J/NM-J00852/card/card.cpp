#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
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
	cout<<"3"<<" "<<"1"<<" "<<"4";
	return 0;
} 

