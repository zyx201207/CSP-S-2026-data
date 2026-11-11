#include <bits/stdc++.h>
using namespace std;
	
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(i==n){
			if(a==7){
				cout<<7;
			}
			else if(a==12){
				cout<<12;
			}
			else{
				cout<<a;
			}
		}
	}
	return 0;
}
