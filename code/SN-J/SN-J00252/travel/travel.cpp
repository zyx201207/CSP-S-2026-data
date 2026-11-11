#include<bits/stdc++.h>
using namespace std;
char f(char a,char b){
	if(a=='A' && (b=='B' || b=='C')) return 1;
	else if(a=='B' && (b=='A' || b=='C')) return 1;
	else if(a=='C' && (b=='B' || b=='A')) return 1;
	else if(b=='A' && (a=='B' || a=='C')) return 1;
	else if(b=='B' && (a=='A' || a=='C')) return 1;
	else if(b=='C' && (a=='B' || a=='A')) return 1;
	else if((a=='D' && b=='F') || (b=='D' && a=='F')) return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_c,c_z,x_c,x_z;
	cin>>c_c>>c_z>>x_c>>x_z;
	if(c_c==x_c) cout<<1;
	else cout<<0;
	int g1=(c_z[0]-'0')*10+(c_z[1]-'0');
	int g2=(x_z[0]-'0')*10+(x_z[1]-'0');
	if(g1==g2 && c_c==x_c) cout<<1;
	else cout<<0;
	if(g1==g2 && c_c==x_c && f(c_z[2],x_z[2])) cout<<1;
	else cout<<0;
	if(g1==g2 && c_c==x_c && f(c_z[2],x_z[2]) && abs(c_z[2]-x_z[2])==1) cout<<1;
	else cout<<0;
} 
