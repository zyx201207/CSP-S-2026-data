#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		if((s1[0]+s1[1])!=(s2[0]+s2[1])){
			cout<<"1000";
		}else{
			char a,b;
			a=s1[2];
			b=s2[2];
			
			int c=0,d=0;
			if((a=='F')||(a=='D')) c=1;
			
			if((b=='F')||(b=='D')) d=1;
			
			if(d==1&&c==1) cout<<"1111";
			else{
				if((c==0)&&(d==1)) cout<<"1100";
				else {
					if(a=='A') {
						if(b=='B') cout<<1111;
						else cout<<"1110";
					}else if(a=='B'){
						if(b=='A' ||b=='C') cout<<1111;
						else cout<<1110;
					}else if(a=='C'){
						if(b=='B'){
							cout<<1111;
						}else cout<<1110;
					}
				}
			}
			
		}
		
	}
	return 0;
}
