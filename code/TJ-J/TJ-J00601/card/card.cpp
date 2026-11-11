#include<bits/stdc++.h>
using namespace std;
int a[1000],n,m,sum;
int main(){
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum=i;
	} 
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+sum]){
			cout <<'1'; 
			break;
		}
	}
	return 0;
} 
