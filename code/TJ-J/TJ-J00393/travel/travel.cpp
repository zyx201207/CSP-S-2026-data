#include<bits/stdc++.h> 
using namespace std;
int a[5],b[5],n=5,x=0,y=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1[5],c2,s2[5];
	cin>>c1>>s1[5]>>c2>>s2[5];
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<n-2;i++){
		if(s1[i]==s2[i]){
			x=1;
		}else{
			x=0;
		}
	}
	cout<<x;
	for(int i=2;i<=n;i++){
	
		if(((s1[i]=="A"||s1[i]=="B"||s1[i]=="C")&&(s2[i]=="A"||s2[i]=="B"||s2[i]=="C"))||((s1[i]=="D"||s1[i]=="F")&&(s2[i]=="D"||s2[i]=="F"))){
			x=1;
		}else{
			x=0;
		}
		if(s1[i]=="D"&&s2[i]=="F"){
			y=1;
		}
		else{
			y=0;
		}
	}
	cout<<x;
	cout<<y;
	return 0;
}
