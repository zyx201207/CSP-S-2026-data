#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[101];
	for(int i=0;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<n;i++){
		i=i-1;
		if(a[i]==a[i+1]){
			break;
		}
		
	}
}
