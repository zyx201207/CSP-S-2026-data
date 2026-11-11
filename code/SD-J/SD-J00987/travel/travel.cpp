//查longlong scanf 模数 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,p1,p2;
	char z1,z2;
	//车厢c 排号p 座号z 
	scanf("%d %d%c",&c1,&p1,&z1);
	scanf("%d %d%c",&c2,&p2,&z2);
	if(c1==c2){
		cout<<'1';
		if(p1==p2){
			cout<<'1';
			if((z1-'A'>2&&z2-'A'>2)||(z1-'A'<=2)&&(z2-'A'<=2)){
				cout<<'1';
				int dis=abs(int(z1-z2));
				if(dis==1){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else{
				cout<<"00";
			} 
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
} 
