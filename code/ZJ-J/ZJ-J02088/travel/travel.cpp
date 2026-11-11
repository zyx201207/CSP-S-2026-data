#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]){
			flag=0;
		}
	}
	cout<<flag;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			flag=0;
		}
	}
	cout<<flag;
	if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>='D'&&s2[2]<'D')){
		flag=0;
	}
	cout<<flag;
	if(max(s1[2],s2[2])-min(s1[2],s2[2])!=1){
		flag=0;		
	}
	cout<<flag;
	return 0;
}
