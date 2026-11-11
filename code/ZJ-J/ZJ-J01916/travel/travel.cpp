//OK
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool is1=(c1==c2),is2=0,is3=0,is4=0;
	if(is1){
		is2=(s1.substr(0,2)==s2.substr(0,2));
		if(is2){
			char rz=s1[2],xz=s2[2];
			int rc=(rz>='A'&&rz<='C');
			int xc=(xz>='A'&&xz<='C');
			is3=(rc==xc);
			if(is3){
				is4=!((rz=='A'&&xz=='C')||(rz=='C'&&xz=='A'));
			}
		}
	}
	cout<<is1<<is2<<is3<<is4;
	return 0;
}