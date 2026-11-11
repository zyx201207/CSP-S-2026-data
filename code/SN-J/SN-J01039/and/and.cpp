#include<bits/stdc++.h>
using namespace std;
int num(int x,int y){
	
}
int n,m,a[20005],b[20005],c[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
	int x=1;
    while(x>=1){
		int i=1;
		a[i]=x%2;
		x/=2;
		i++;
	}
	while(y>=1){
		int i=1;
		b[i]=y%2;
		y/=2;
		i++;
	}
	return 0;
} 
