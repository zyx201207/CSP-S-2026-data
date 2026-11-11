#include <iostream>
#include <cstdio> 
#include <math.h>
using namespace std;
long int a[10005]={},d[10005]={},s[10005]={};
bool i[30005]={};
int r(int n,int l,int y){
	for(int x=l;x<n;x++){
		if(i[a[x]]==0){
			i[a[x]]=1;
			d[y]=a[x];
			y++;
		}else{
			while(d[y]!=a[x]){
				a[y]=0;
				y--;
			}
			y++;
		}
	}
	for(int x=0;x<y;x++){
		s[d[x]]++;
		cout<<d[x]<<" ";
	}
	cout<<endl;
}
int main() {
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int x=0;x<n;x++){
		cin>>a[x];
	}
	for(int x=0;x<n;x++){
		r(n,x,0);
	}
	for(int x=1;x<=m;x++){
		cout<<s[x]<<" ";
	}
	return 0;
}
