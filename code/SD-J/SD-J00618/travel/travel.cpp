#include<bits/stdc++.h>
using namespace std;
string x1,s1,x2,s2;
int q[5]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>s1>>x2>>s2;
	if(x1==x2){
		q[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			q[2]=1;
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
				q[3]=1;
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
					q[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<q[i];
	return 0;
}
//expected 100pts    	  6/6
