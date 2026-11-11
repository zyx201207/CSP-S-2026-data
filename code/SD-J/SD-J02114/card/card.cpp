#include<bits/stdc++.h>
using namespace std;
#define Q 500002
int main(){
	int l[Q],c[Q],e[Q],n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>l[i];
	}
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[j]==l[i]){
				for (int z=j;z<=n;z++){
					c[z-j+1]=l[j];
					for (int x=1;x<=n-j;x++){
						
					}
				}
			}
		}
	}
	cout<<l;
	return 0;
}
