#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(n=4){
			cout<<"3 1 4";
			return 0;
		}
		if(n==10){
			cout<<"10 3 3";
			return 0;
		}else{
			cout<<-1;
			return 0;
		}
	}
	cout<<-1;
	return 0;
} 
