#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}//两张车票对应的座位是否在同一节车厢；

	int f=1;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]) f=0;
	}
	if(f==0){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}//两张车票对应的座位是否在同一节车厢的同一排；
	
	int a=s1.size()-1,b=s2.size()-1;
	if(s1[a]<='C'&&s2[b]<='C'||s2[b]>='D'&&s1[a]>='D'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	if(abs(s1[a]-s2[b])==1||s1[a]=='D'&&s2[b]=='F'||s1[a]=='F'&&s2[b]=='D'){
		if(s1[a]!='D'&&s2[b]!='C'||s2[b]!='D'&&s1[a]!='C'){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	}else{
		cout<<"0";
	}//两张车票对应的座位是否相邻
	//cout<<endl<<s1[a]<<" "<<s2[b];
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
