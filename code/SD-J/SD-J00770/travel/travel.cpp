#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	int anst[4];
	memset(anst,0,sizeof(anst));
	if(cr==cx){
		anst[0]=1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			anst[1]=1;
			if((sr[2]=='D'&&sx[2]!='F')||(sr[2]=='F'&&sx[2]!='D')||(sr[2]!='D'&&sx[2]=='F')||(sr[2]!='F'&&sx[2]=='D')){
				anst[2]=0;
			}else{
				anst[2]=1;
				int xt,yt;
				xt=sr[2];
				yt=sx[2];
				if(abs(xt-yt)==1){
					anst[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<anst[i];
	}
	return 0;
}
