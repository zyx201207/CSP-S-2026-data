#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<"1";
		int p1=(int)(b1[0]-'0')*10+(int)(b1[1]-'0'),p2=(int)(b2[0]-'0')*10+(int)(b2[1]-'0');
		if(p1==p2){
			cout<<"1";
			int z1=(int)(b1[2]-'A'+1),z2=(int)(b2[2]-'A'+1);
			if((z1<=3&&z2<=3)||(z1>=4&&z2>=4)){
				cout<<"1";
				if(abs(z1-z2)>1||((z1==3&&z2==4)||(z1==4&&z2==3))){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}