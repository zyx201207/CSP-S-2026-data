#include<bits/stdc++.h>
using namespace std;
int d[0];
int main(){
	fropen("card.in","r",stdin);
	fropen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=a;i++){
		cin>>a;
		d[0]+a;
	}
	for(int j=1;j<=a;j++){	
		for(int z=0;z<=j;j++){
			if(d[a]==1){
				b+1;
		}
		}
	}

	return 0;
}