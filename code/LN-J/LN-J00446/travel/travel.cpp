#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[5],d[5];
int a=-1,b=-1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>m>>c>>n>>d;
if(m==n)
cout<<1;

else{
cout<<"0000";
return 0;
}
for(int i=0;i<2;i++){

if(c[i]!=d[i]){
cout<<"000";
return 0;
}

}
cout<<1;
if(c[2]=='A'||c[2]=='B'||c[2]=='C')
a=1;
if(c[2]=='D'||c[2]=='F')
a=0;
if(d[2]=='A'||d[2]=='B'||d[2]=='C')
b=1;
if(d[2]=='D'||d[2]=='F')
b=0;
if(a==1&&b==1)
cout<<1;
else{
	if(a==0&&b==0){
	cout<<11;
	return 0;
}
else{
cout<<"00";
return 0;
}
}
if(c[2]-d[2]==1||c[2]-d[2]==-1)
cout<<1;
else
cout<<0;

}

