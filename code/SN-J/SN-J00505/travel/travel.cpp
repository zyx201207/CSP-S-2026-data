#include<bits/stdc++.h>
using namespace std;
#define int long long
bool f3(char a,char b){
	if(a=='A'&&(b=='B'||b=='C'))return 1;
	else if(a=='B'&&(b=='A'||b=='C'))return 1;
	else if(a=='C'&&(b=='A'||b=='B'))return 1;
	else if(a=='D'&&b=='F')return 1;
	else if(a=='F'&&b=='D')return 1;
	else return 0;
}
bool f4(char a,char b){
	if(a=='A'&&b=='B')return 1;
	else if(a=='B'&&(b=='A'||b=='C'))return 1;
	else if(a=='C'&&b=='B')return 1;
	else if(a=='D'&&b=='F')return 1;
	else if(a=='F'&&b=='D')return 1;
	else return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	string b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int k1=0,k2=0,k3=0,k4=0;
	if(a1==b1){a
		k1=1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			k2=1;
			if(f3(a2[2],b2[2])){
				k3=1;
				if(f4(a2[2],b2[2])){
					k4=1;
				}
			}
		}
	}
	cout<<k1<<k2<<k3<<k4;
	return 0;
} 
