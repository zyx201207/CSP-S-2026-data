#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string rz,xz;
    int rc,xc;
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc){
    	cout<<1;
    	if(rz[0]==xz[0]&&rz[1]==xz[1]){
		    cout<<1;
		    if((int(rz[2])-64<=3&&int(xz[2])-64<=3)||(int(rz[2])-64>3&&int(xz[2])-64>3)){
		    	cout<<1;
		    	if(rz[2]-xz[2]==1||rz[2]-xz[2]==-1){
		    		cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
	    }
	    else{
		cout<<"000";
	    }
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
return 0;
} 
