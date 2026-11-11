#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string p1,p2,xo1,xo2;
	cin>>p1>>xo1>>p2>>xo2;
	if(p1==p2){
		cout<<"1"<<endl;
		if(xo1[0]==xo2[0] and xo1[1]==xo2[1]){
			cout<<"1"<<endl;
			if(xo1[2]+xo2[2]<=134 or xo1[2]+xo2[2]>=136){
				cout<<"1"<<endl;
				if(xo1[2]-xo2[2]==1 or xo1[2]-xo2[2]==-1){
					cout<<"1"<<endl; 
				}else{
					cout<<"0"<<endl;
				}
			}else{
				cout<<"0"<<endl<<"0"<<endl;
			}
		}else{
			cout<<"0"<<endl<<"0"<<endl<<"0"<<endl;
		}
	}else{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
