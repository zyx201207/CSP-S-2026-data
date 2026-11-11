#include<bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb;
bool answer[4]={0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca[0]==cb[0]&&ca[1]==cb[1]){
		answer[0]=true;
		
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			answer[1]=true;
			if(int(sa[2])<=67&&int(sb[2])<=67||int(sa[2])>=68&&int(sb[2])>=68){
				answer[2]=true;
				if(abs(int(sa[2])-int(sb[2]))==1){
					answer[3]=true;
				}
			}
		}
	}for(int i=0;i<4;i++){
		if(answer[i])cout<<1;
		else cout<<0;
	}
	return 0;
}
