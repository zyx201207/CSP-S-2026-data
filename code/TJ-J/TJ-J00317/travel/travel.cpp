#include<bits/stdc++.h>
using namespace std;
/*struct ticket{
	int a,b;
}x[10];*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int a = a1[0]+a1[1]-96;
	int b = b1[0]+b1[1]-96;
	int x = a2[0]+a2[1]-96;
	int y = b2[0]+b2[1]-96;
	int v = a2[2]-48;
	int w = b2[2]-48;
	if(a == b){
		cout<<1;
		if(x==y){
			cout<<1;
			if(v<=19&&w<=19){
				cout<<1;
				if(abs(v-w)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(v>19&&w>19){
				cout<<1;
				cout<<1;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
