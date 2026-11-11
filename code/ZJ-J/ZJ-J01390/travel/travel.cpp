#include<iostream>
using namespace std;
int a,b;
char c1[10],c2[10];
bool f(char c){
	return c=='A'||c=='B'||c=='C';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c1+1>>b>>c2+1;
	if(a!=b)cout<<"0000\n";
	else{
		if(c1[1]!=c2[1]||c1[2]!=c2[2])cout<<"1000\n";
		else{
			if(f(c1[3])!=f(c2[3]))cout<<"1100\n";
			else{
				if(c1[3]-c2[3]==1||c1[3]-c2[3]==-1)cout<<"1111\n";
				else cout<<"1110\n";
			}
		}
	}
	return 0;
}