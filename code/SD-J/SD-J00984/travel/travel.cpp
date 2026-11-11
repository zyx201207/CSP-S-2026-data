# include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int vis[4];
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){//同一车厢 
		vis[0] = 1;
		char tmpa = sa[0]+sa[1];
		char tmpb = sb[0]+sb[1];
		if(tmpa==tmpb){//同一列 
			tmpa = sa[2];
			tmpb = sb[2];
			if(tmpa=='A'||tmpa=='B'||tmpa=='C'){
				if(tmpb=='A'||tmpb=='B'||tmpb=='C'){
					vis[2] = 1;
				}
			}
			else{
				if(tmpb=='D'||tmpb=='E'){
					vis[2] = 1;
				}
			}
			
			if(tmpa=='F'||tmpa=='C'||tmpa=='B'){//相邻 
				if(tmpb==tmpa-1){
					vis[3] = 1;
				}
			}
			else{
				if(tmpb==tmpa-1){
					vis[3] = 1;
				}
			}
		}
	}
	
	for(int i=0;i<4;i++){
		printf("%d",vis[i]);
	}
	return 0;
}

