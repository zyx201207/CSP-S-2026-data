#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int num,cnt,h;
int a[3],b[3];
char p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n=c1.size();
	for(int i=0;i<n;i++){
		if(c1[i]==c2[i]) num++;
	}
	if(num==2) cout<<"1";
	else{cout<<"0000"; return 0;}
	if(num==2){
		for(int w=0;w<3;w++){
			a[w]=(int)s1[w];
			b[w]=(int)s2[w];
			if(a[w]==b[w]) cnt++; 
		}
		if(cnt==2) {cout<<"1";
			if(s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C'){
				cout<<"1";
				if((int)s1[2]==(int)s2[2]+1||(int)s1[2]==(int)s2[2]-1){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{cout<<"000"; return 0;}
	}
	return 0;
}
