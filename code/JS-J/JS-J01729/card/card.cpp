#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[300005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	return 0;
}
