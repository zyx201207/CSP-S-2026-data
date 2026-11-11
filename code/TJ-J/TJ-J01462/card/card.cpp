#include<iostream>
using namespace std;
int a[100000];
int g;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		if(a[i]==m&&a[i]+a[i+1]==i){
			 g=a[i];
		}
	} 
	for(int i=1;i<=m;i++){
		if(a[i-1]!=a[i]){
			g-=a[i];
		}
	}
	cout<<g;
	return 0;
}
