#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string cj;
string z;
string cj1;
string z1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cj>>z>>cj1>>z1;
	if(cj==cj1){
		cout<<1;
	}else{
		cout<<0;
	}
	int len=z.size();
	int len1=z1.size();
	char C=C;
	if(z[0]==z1[0]&&z[1]==z1[1]){
		cout<<1;
		if(z[2]<=C&&z1[2]<=C||z[2]>=C&&z1[2]>=C){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(z1[2]=='D'&&z[2]=='C'||z[2]=='D'&&z1[2]=='C'){
		cout<<0;
		return 0;
	}
	if(abs(z[2]-z1[2])==1){
				cout<<1;
			}else{
				cout<<0;
			}
	return 0;
}
