#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r","stdin");
	freopen("magrate.out","w","stdout");
	int c,t,n,d;
	cin>>c>>t;
	for(int b=1;b<=t;b++){
		int a[2000009]={},sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i+2==j){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
