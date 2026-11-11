#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500000],som=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	int b=a[0]; 
	for(int i=1;i<=n;i++){
		if(a[i]==b){
			som++;
		}
		
	}
	cout<<som;
	
	return 0;
}
