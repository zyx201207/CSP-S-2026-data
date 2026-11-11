#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cn1=(int(c1[0])-48)*10+(int(c1[1])-48),cn2=(int(c2[0])-48)*10+(int(c2[1])-48);
	int sn1=(int(s1[0])-48)*10+(int(s1[1])-48),sn2=(int(s2[0])-48)*10+(int(s2[1])-48);
	char sd1=s1[2],sd2=s2[2];
	if(cn1==cn2){
		cout<<"1";
		if(sn1==sn2){
			cout<<"1";
			if(((sd1=='A' || sd1=='B' || sd1=='C') && (sd2=='A' || sd2=='B' || sd2=='C')) || ((sd1=='D' || sd1=='F') && (sd2=='D' || sd2=='F'))){
				cout<<"1";
				if(int(sd1)+1==int(sd2) || int(sd2)+1==int(sd1) || ((sd1=='D' || sd1=='F') && (sd2=='D' || sd2=='F'))){
					cout<<"1";
					
				}
				else{
					cout<<"0";
				}
			}
			else {
				cout<<"00";
				return 0;
			}
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
