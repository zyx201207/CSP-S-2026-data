#include<bits/stdc++.h>
using namespace std;
int main(){
	
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int  c,n,m,d,q;
	int w[100000000],a[100000][1000000],t[100000][1000000];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for (int i=1;1<n;i++){
		int b;
		cin>>b;
		for (int j=0;j<=b;j++){
			cin>>a[i][j]<<t[i][j];
		}
	}
	
	for(int i=0;i<2;i++){
	int x,y;
	cin>>x>>y;	
	}
	int i=-1,j=-1,f,e;
	while(1){
		if(x=a[i][j]){
			f=w[i];
			if()
			
		}
		else{
			j++;
		}
	}
	
	return 0;
}
