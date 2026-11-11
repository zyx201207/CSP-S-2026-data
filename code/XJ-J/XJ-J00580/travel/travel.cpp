#include <bits/stdc++.h>
using namespace std;
int arr[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		arr[0]=1;
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				arr[1]=1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					arr[2]=1;
					if(s1[2]==s2[2]-1||s2[2]==s1[2]-1){
						arr[3]=1;
					}
				}
					
				
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					arr[2]=1;
					if(s1[2]==s2[2]-1||s2[2]==s1[2]-1){
						arr[3]=1;
					}
				}
			
	
		}
	}
		}
	}
	
	
	
	cout<<arr[0]<<arr[1]<<arr[2]<<arr[3];
	return 0;
}