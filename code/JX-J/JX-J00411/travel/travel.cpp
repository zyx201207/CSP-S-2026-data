#include<bits/stdc++.h>
using namespace std;
bool a[5];
int cnt;
int main (){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string c1,s1,c2,s2;
   cin>>c1>>s1>>c2>>s2;
   int cd2=s1.size(),cd4=s2.size();
   if(c1==c2){
	   a[0]=1;
   }
   for(int i=0;i<cd2-1;i++){
	   for(int j=0;j<cd4-1;j++){
		   if(s1[i]==s2[j]){
			   cnt++;
		   }
		   if(cnt==2){
			   a[1]=1;
			   break;
		   }
	   }
   }
   bool flag=0,flag2=0;
   for(char i='A';i<='C';i++){
	   if(s1[cd2-1]==i){
		   flag=1;
	   }
	   if(s2[cd4-1]==i){
		   flag2=1;
	   }
   }
   if(flag==1&&flag2==1){
	   a[2]=1;
   }
   if(s1[cd2-1]=='C'&&s2[cd4-1]=='D'){
	   if(s1[cd2-1]=='D'&&s2[cd4-1]=='C'){
	   a[3]=0;
   }
   } 
   else{
	   
   if(s1[cd2-1]-1==s2[cd4-1]||s1[cd2-1]+1==s2[cd4-1]){
	       a[3]=1;
   }
}
   if(s1[cd2-1]>='D'&&s1[cd2-1]<='F'&&s2[cd4-1]>='D'&&s2[cd4-1]<='F'){
	   a[2]=1;
	  
   }
   for(int i=0;i<4;i++){
	   cout<<a[i];
   }
	   return 0;
}
