#include<bits\stdc++.h>
using namespace std;
int main(){
        freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char set[2];
	cin>>set[0]>>set[1];
    char where[3];
    cin>>where[0]>>where[1]>>where[2];
    char set_1[2];
	cin>>set_1[0]>>set_1[1];
    char where_1[3];
    cin>>where_1[0]>>where_1[1]>>where_1[2];
    char whe[5] = {'A','B','C','D','F'};
    int the = 0;
    int the_1 = 0;
    if(set[0] == set_1[0] && set[1] == set_1[1]){
    	cout<<"1";
	}
	else{
		cout<<"0";
	}
    if(where[0] == where_1[0] && where_1[1] == where[1]){
    	cout<<"1";
    	if(((where[2] == 'A' || where[2] == 'B'||where[2] == 'C') && (where_1[2] == 'A' || where_1[2] == 'B'||where_1[2] == 'C')) || ((where[2] == 'D' || where[2] == 'F') && (where_1[2] == 'D' || where_1[2] == 'F'))){
    		cout<<"1";
    		for(int i(0);i<5;i++){
    			if(where[2] == whe[i]){
    				the = i;
				}
			}
			for(int i(0);i<5;i++){
    			if(where_1[2] == whe[i]){
    				the_1 = i;
				}
			}
			if(the == the_1-1||the == the_1+1){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}
	else{
		cout<<"000";
	}
	
}
