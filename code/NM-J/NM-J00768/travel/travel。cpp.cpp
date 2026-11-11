#include <bits/stdc++.h>
using namespace std;

int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
string c1,c2,s1,s2;
int a[4]={0};
int k=0;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
        a[k]=1;
    k++;
    if(s2[0]==s1[0]&&s2[1]==s1[1]){
      a[k]=1;
        k++;
    }else{
        a[k]=0;
        k++;
    
}
if(s1[2]=='d'&&s2[2]=='f'){
	a[2]=1;
	k++;
}else if(s1[2]!='d'&&s2[2]!='f'){
	a[2]=1;
	k++;
	if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
	a[3]=1;
	k++;
	
		}else{
	a[3]=0;
	k++;

}
}else {
	a[2]=0;
	a[3]=0;
}


if(s1[2]=='D'&&s2[2]=='F'){
	a[2]=1;
	k++;
}else if(s1[2]!='D'&&s2[2]!='F'){
	a[2]=1;
	k++;
	if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
	a[3]=1;
	k++;
	
}else{
	a[3]=0;
	k++;

}
}else {
	a[2]=0;
	a[3]=0;
}
if(s2[2]=='d'&&s1[2]=='f'){
	a[2]=1;
	k++;
}else if(s2[2]!='d'&&s1[2]!='f'){
	a[2]=1;
	k++;
	if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
	a[3]=1;
	k++;
	
}else{
	a[3]=0;
	k++;

}
}else {
	a[2]=0;
	a[3]=0;
}


if(s2[2]=='D'&&s1[2]=='F'){
	a[2]=1;
	k++;
}else if(s2[2]!='D'&&s1[2]!='F'){
	a[2]=1;
	k++;
	if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
	a[3]=1;
	k++;
	
}else{
	a[3]=0;
	k++;

}
}else {
	a[2]=0;
	a[3]=0;
}

}else{
	for(int i=0;i<4;i++){
		a[i]=0;	
	}
}




	











for(int i=0;i<4;i++){
	cout<<a[i]<<" ";
}








return 0;



}
