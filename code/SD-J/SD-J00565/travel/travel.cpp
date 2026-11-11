#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a[5]={0,0,0,0};
int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		a[0]=1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			a[1]=1;
			
			if(c1[3]=='D'&&c2[3]=='F'||c2[3]=='D'&&c1[3]=='F'){
				cout<"1111";
			}
			else if(c1[3]=='B'||c2[3]=='B'){
				if(c1[3]>c2[3]){
					if(c1[3]-c2[3]==1){
						cout<<"1111";
					}
					else{
						cout<<"1110";
					}
				}
				else{
					if(c2[3]-c1[3]==1){
						cout<<"1111";
					}
					else{
						cout<<"1110";
					}
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			for(int i=0;i<4;i++){
				cout<<a[i];
			}
		}
	}
	else{
		for(int i=0;i<4;i++){
			cout<<a[i];
		}
	}
	return 0;
} 
