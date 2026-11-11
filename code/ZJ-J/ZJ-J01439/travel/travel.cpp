#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xa,xb,pa,pb;
	char za,zb;
	scanf("%d %d%c %d %d%c",&xa,&pa,&za,&xb,&pb,&zb);
	if(xa==xb){
		if(pa==pb){
			if((za<='C' && zb<='C')||(za>='D' && zb>='D')){
				if((za=='A' && zb=='B') || (za=='B' && zb=='A') || (za=='B' && zb=='C') || (za=='C' && zb=='B') || (za=='D' && zb=='F') || (za=='F' && zb=='D')){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
}
