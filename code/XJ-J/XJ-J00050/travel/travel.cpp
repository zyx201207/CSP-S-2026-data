#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int daan1=0;
	int daan2=0;
	int daan3=0;
	int daan4=0;
	string s3="ABCDEF";
	if(c1==c2){
		daan1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    daan2=1;
		    if(s1[2]>=s3[0]&&s1[2]<=s3[2]){
		    	if(s2[2]>=s3[0]&&s2[2]<=s3[2]){
		    		daan3=1;
				}
			}
		    if(s1[2]>=s3[3]&&s1[2]<=s3[4]){
		    	if(s2[2]>=s3[3]&&s2[2]<=s3[4]){
		    		daan3=1;
				}
			}
		    	
			if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
				daan4=1;
			}
	    }
	}
	cout<<daan1<<daan2<<daan3<<daan4<<endl;
	return 0;
} 
