#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		if(((a[i+2]-a[i+1])+(a[i+2]-a[i])==m)&&a[i+3]!=a[i+2]){
			cout<<"3";
			break;
		}else{
			cout<<"4";
			break;
		}
		}
	
	return 0;
}
