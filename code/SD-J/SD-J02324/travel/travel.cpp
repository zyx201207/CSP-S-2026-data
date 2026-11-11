#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rxiang,Xxiang,Rzuo,Xzuo;
	cin>>Rxiang>>Rzuo>>Xxiang>>Xzuo;
	if(Rxiang!=Xxiang)cout<<"0000";
	else{
		if((Rzuo[0]!=Xzuo[0])||(Rzuo[1]!=Xzuo[1]))cout<<"1000";
		else{
			if((Rzuo[2]<='C'&&Xzuo[2]<='C')||(Rzuo[2]>='D'&&Xzuo[2]>='D'))
			{
				if(((Rzuo[2]-1)==Xzuo[2])||((Xzuo[2]-1)==Rzuo[2]))cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	return 0;
}
