#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[20000],c,b[300000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c;
		b[i]=c;
		a[c]++;
		for(int j=0;j<i;j++){
			if(b[j]==c){
				for(int x=j;x<i;x++){
					b[x]=-1;
				}
			}
			a[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
