#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<'\n';
	} else{
		cout<<1;
		if(s1[0]!=s2[0] || s1[1]!=s2[1]){
			cout<<"000"<<'\n';
		} else{
			cout<<1;
			if((s1[2]>='A' && s1[2]<='C' && s2[2]>='D' && s2[2]<='F') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
				cout<<"00"<<'\n';
			} else{
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1<<'\n';
				} else{
					cout<<0<<'\n';
				}
			}
		}
	}
	return 0;
}

