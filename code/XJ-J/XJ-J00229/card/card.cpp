#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r"stdin);
	freopen("card.out","w"stdout);
	int n,m,a[10000],h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int k=0;k<m;k++){
			if(a[i]==a[k]){
				a[k]=a[i];
				i=k;
			}
		}
	}
	for(int i=1;i<=n;i++){
		h=0;
		for(int j=0;j<m;j++){
			if(a[i]==j){
				h++;
			}
		}
		cout<<h;
	}
	return 0;
}
