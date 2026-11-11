#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<m<<" ";
	for(int i=1;i<m;i++){
		cout<<i<<" ";
	}
	for(int i=1;i<=n-m;i++){
		cout<<m<<" ";
	}
	return 0;
}
