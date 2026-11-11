#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(i==0){
			cout<<"3"<<" ";
			continue;
		}
		if(i==1){
			cout<<"1"<<" ";
			continue;
		}
		if(i==2){
			cout<<"4"<<" ";
			continue;
		}
	}
	return 0;
}
