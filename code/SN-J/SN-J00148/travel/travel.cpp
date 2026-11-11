#include<bits/stdc++.h>
using namespace std;
bool camp(char r,char t){
	if(((r=='A' or r=='B' or r=='C')and(t=='A' or t=='B' or t=='C')) or ((r=='D' or r=='F')and(t=='D' or t=='F'))){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		char w1[10],w2[10];
		for(int i=0;i<3;i++){
			w1[i]=b[i];
			w2[i]=d[i];
		}
		if(w1[0]==w2[0] and w1[1]==w2[1]){
			if(camp(w1[2],w2[2])){
				if((w1[2]=='A' and w2[2]=='C') or (w2[2]=='A' and w1[2]=='C')){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
				
			}else{
				cout<<"1100";
			} 
		}else{
			cout<<"1000";
		}
		
	}else{
		cout<<"0000";	
	}



	return 0;
}
