#include<bits/stdc++.h>
using namespace std;
string mys1,mys2;
int myc1,myc2;
int main(){
	freopen("travel.in","r",stdin); //!!!
	freopen("travel.out","w",stdout); //!!!
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>myc1>>mys1>>myc2>>mys2;
	int pai1=(mys1[0]-'0')*10+mys1[1]-'0';
	int pai2=(mys2[0]-'0')*10+mys2[1]-'0';
	bool che=(myc1==myc2);
	bool pai=che&&(pai1==pai2);
	bool ce=pai&&((mys1[2]<='C'&&mys2[2]<='C')||(mys1[2]>='D'&&mys2[2]>='D'));
	bool ling=ce&&((mys1[2]<='C'&&(abs(mys1[2]-mys2[2])==1))||(mys1[2]>='D'));
	cout<<che<<pai<<ce<<ling;
	return 0;
}