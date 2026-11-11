#include<bits/stdc++.h>
using namespace std;
int q[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b;
	cin>>a>>b;
for(int i=1;i<=b;i++){
	int x,y,z=0,sum=0,sam=0;
	cin>>x>>y;
	for(int w=1;w<=x;w++){
		cin>>q[i];
	}z=q[2]-q[1];
for(int i=1;i<=x;i++){
	for(int u=1;u<=x;u++){
		for(int j=1;j<=u-1;j++){
			if((u-1)*y>=q[u]-q[i]){
				sum++;
			}
		}
	}if(sum==2){
		sam++;
	}
} 
	cout<<sam;
} 
	 
	return 0;
}

