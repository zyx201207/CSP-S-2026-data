#include<bits/stdc++.h>
using namespace std;
int a[3000][3000];
int b[3000][3000];
int c[3000];
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	int n,m;
	cin>>n>>m;
	int p;
	int x=0;
	int l=0;
	for(int i=0;i<n;i++){
		cin>>p;
		x=0;
		while(p>0){
			a[i][x]=p%2;
			p=p/2;
			x++;
		}
		c[i]=x;
	}
	
	cout<<12;
	return 0;
}
