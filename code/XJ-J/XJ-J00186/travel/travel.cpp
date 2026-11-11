#include<bits/stdc++.h>
using namespace std;
string acp,bcp,acx,bcx;
bool flag[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>acx>>acp>>bcx>>bcp;
	if(acx==bcx){
		flag[1]=1;
		if(acp[0]==bcp[0]&&acp[1]==bcp[1]){
			flag[2]=1;
			if((('A'<=acp[2]&&acp[2]<='C')&&('A'<=bcp[2]&&bcp[2]<='C'))||(('E'<=acp[2]&&acp[2]<='F')&&('E'<=bcp[2]&&bcp[2]<='F'))){
				flag[3]=1;
				if((((acp[2]-'0')+1)==bcp[2]-'0')||(((acp[2]-'0')-1)==bcp[2]-'0')){
					flag[4]=1;
				}
			}
		}
	}
	bool if0=0;
	for(int i=1;i<=4;i++){
		if(flag[i]&&!if0){
			cout<<1;
		}else{
			if0=1;
			cout<<0;
		}
	}
	return 0;
}

