#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int a=1;
	for(int i=0;i<t;i++){
		if(a==1){
		 	cout<<"1"<<endl;
		 	a=2;
		}
		else{
		 	cout<<"2"<<endl;
		 	a=1;
		}
	}
	return 0;
} 
