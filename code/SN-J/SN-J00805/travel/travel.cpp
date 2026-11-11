//姓名：张晨煦   考号：SN-J00805   学校：西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
string r_x,r_z,x_x,x_z;
bool a,b,c,d;
bool if_l(char a){
	if(a=='A' || a=='B' || a=='C') return true;
	else if(a=='D' || a=='F') return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>r_x>>r_z>>x_x>>x_z;
	if(r_x!=x_x) cout<<"0000"<<'\n';
	else if(r_x==x_x){
		if(r_z[0]==x_z[0] && r_z[1]==x_z[1]){
			if(if_l(r_z[2])==if_l(x_z[2])){
				if(abs(int(r_z[2])-int(x_z[2]))==1) cout<<"1111"<<'\n';
				else cout<<"1110"<<'\n';
			}
			else cout<<"1100";
		}
		else cout<<"1000"<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
