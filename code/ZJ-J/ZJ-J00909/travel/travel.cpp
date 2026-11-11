#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t1,t2,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t1=s1[0]+s1[1];
	a1=s1[2];
	t2=s2[0]+s2[1];
	a2=s2[2];
	if(c1==c2){
		cout<<"1";
		if(t1==t2){
			cout<<"1";
			if("A"<=a1&&a1<="C"&&"A"<=a2&&a2<="C"||"D"<=a1&&a1<="E"&&"D"<=a2&&a2<="E"){
				cout<<"1";
				if(!(a1=="C"&&a2=="D"||a1=="D"&&a2=="C")&&!(a1=="A"&&a2=="C"||a1=="C"&&a2=="A")){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}