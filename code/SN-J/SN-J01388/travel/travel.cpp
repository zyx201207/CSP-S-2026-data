#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int i1,i2,j1,j2,k1,k2,l1,l2;
	i1=(c1[0]-48)*10+(c1[1]-48);
	i2=(c2[0]-48)*10+(c2[1]-48);
	j1=(s1[0]-48)*10+(s1[1]-48);
	j2=(s2[0]-48)*10+(s2[1]-48);
	k1=s1[2]-64;
	k2=s2[2]-64;
	if(k1==1 or k1==2 or k1==3){
		l1=1;
		
	}else{
		l1=0;
	}	
	if(k2==1 or k2==2 or k2==3){
		l2=1;
	}else{
		l2=0;
	}
	if(i1==i2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(j1==j2 and i1==i2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(l1==l2 and (j1==j2 and i1==i2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if((k1+1==k2 or k1-1==k2) and (l1==l2 and (i1==i2 and j1==j2))){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
