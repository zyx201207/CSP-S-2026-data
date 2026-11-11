#include<bits/stdc++.h>	

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string r[10],x[10];
	for(int i=0;i<3;i++){
		r[i]=s1[i];
	}
	for(int i=0;i<3;i++){
		x[i]=s2[i];
	}
	int x1=0,x2=0,x3=0,x4=0;
	if(c1==c2){
		x1=1;
		if(r[0]==x[0] && r[1]==x[1]){
			x2=1;
			if(r[2]=="A" && "B" && "C" || x[2]=="A" && "B" && "C"){
				x3=1;
				if(r[2]=="A"){
					if(x[2]=="B"){
						x4=1;
					}
				}
				if(r[2]=="B"){
					if(x[2]=="A" && "C"){
					x4=1;
					}
				}
				if(r[2]=="C"){
					if(x[2]=="B"){
						x4=1;
					}
				}
			}
			if(r[2]=="D" && "F" || x[2]=="D" && "F"){
				if(r[2]=="D"){
					if(x[2]=="F"){
						x4=1;
					}
				}
				if(r[2]=="F"){
					if(x[2]=="D"){
						x4=1;
					}
				}
			}
		}
	}
	cout<<x1<<x2<<x3<<x4;
	return 0;
}
