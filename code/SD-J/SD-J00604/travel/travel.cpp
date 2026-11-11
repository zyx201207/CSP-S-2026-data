#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[10];
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//在同一节车厢 
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){//在同一排 
			a[1]=1;
			if(s1[2]=='A'){
				if(s2[2]=='B')a[2]=1,a[3]=1;
				else if(s2[2]=='C')a[2]=1;
			}
			else if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C')a[2]=1,a[3]=1;
			}	
			else if(s1[2]=='C'){
				if(s2[2]=='B')a[2]=1,a[3]=1;
				else if(s2[2]=='A')a[2]=1;
			}
			else if(s1[2]=='D'&&s2[2]=='F')a[2]=1,a[3]=1;
			else if(s1[2]=='F'&&s2[2]=='D')a[2]=1,a[3]=1;
		}
	}
	for(int i=0;i<4;i++)cout<<a[i];
	return 0;
}

