#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
string q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		q+='1';
		if(c2[0]==c4[0] and c2[1]==c4[1]){
			q+='1';
			if((c2[2]>='D' and c4[2]>='D') or (c2[2]<='C' and c4[2]<='C')){
				q+='1';
				if(c2[2]+1==c4[2] or c2[2]-1==c4[2]){
					q+='1';
				}else{
					q="1110";
				}
			}else{
				q="1100";
			}
		}else{
			q="1000";
		}
	}else{
		q="0000";
	}
	cout<<q<<endl;
	return 0;
}
