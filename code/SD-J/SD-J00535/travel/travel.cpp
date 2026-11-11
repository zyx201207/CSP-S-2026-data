#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ss1,ss2,ss11,ss22;
char b,c;
int a[7];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ss1=s1[0]+s1[1];
	ss11=s1[2];
	ss2=s2[0]+s2[1];
	ss22=s2[2];
	b=s1[2];
	c=s2[2];
	if(c1==c2){
		a[1]=1;
		if(ss1==ss2) {
			a[2]=1;
			if(((ss11=="A"||ss11=="B"||ss11=="C")&&(ss22=="A"||ss22=="B"||ss22=="C"))||((ss11=="D"||ss11=="F")&&(ss22=="D"||ss22=="F"))) {
				a[3]=1; 
				if(b+1==c||b-1==c){
					a[4]=1; 
				}
				else{
					a[4]=0;
				}
			}
			else{
				a[3]=0;
			}
		}
		else{
			a[2]=0;
		}
	}
	else{
		a[1]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
