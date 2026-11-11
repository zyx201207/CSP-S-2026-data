#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	string r1,x1;
	cin>>r>>r1>>x>>x1;
	for(int i=1;i<=4;i++){
		if(r==x){
			a[1]+=1;
			break;	
		} 
	}
	for(int i=1;i<=4;i++){
		if(r1!=x1){
			a[2]+=1; 
			break;
		} 
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0; 
}
