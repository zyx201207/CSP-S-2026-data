#include<bits/stdc++.h>
using ll=long long;
using namespace std;
struct node{
	int cx;
	int pai;
	int id;
}a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	for(int i=1;i<=2;i++){
		cin>>a[i].cx>>s;
		a[i].pai=int(s[0])*10+int(s[1]);
		a[i].id=int(s[2]-'A')+1;
	}
	if(a[1].cx==a[2].cx){
		cout<<"1";
		if(a[1].pai==a[2].pai){
			cout<<"1";
			if(((a[1].id==1||a[1].id==2||a[1].id==3)
			&&(a[2].id==1||a[2].id==2||a[2].id==3))
		    ||((a[1].id==4||a[1].id==5)
			&&(a[2].id==4||a[2].id==5))){
				cout<<"1";
				if(a[1].id==a[2].id+1
				||a[1].id==a[2].id-1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
} 
