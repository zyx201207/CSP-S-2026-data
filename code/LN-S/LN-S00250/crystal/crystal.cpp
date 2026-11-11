#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen(“crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
int n,m=7,x,z=0,v=0;
cin>>n>>m;
int a[100];
n=n-1;
for(int i=0;i<=n;i++){
cin>>a[i];
}



for(int j=0;j<=n;j++){
for(int i=1;i<=n;i++){
if(a[i]>a[i-1]){
x=a[i-1];
a[i-1]=a[i];
a[i]=x;
}
}
}




/*int j=0;

for(int i=0;i<n;i++){
while(m>=0){
    j=i+0;
if(j>=n)
{
 break;
}
while(a[j+1]==a[j])
{
 a[j+1]=a[j+1]+1;
 m--;

}z++;j++;
}
}*/



/*
v=n/2;



for(int i=1;i<=v;i++){
   
while(a[v+i]!=a[v]){
a[v+i]=a[v+i]+1;

if(m>=0){
    break;
}}z++;}
*/



for(int j=0;j<=n;j++){
z=0+0;
for(int i=0;i<=n;i++){



a[j+i+1]=a[j+i];
m=m-(a[j+i]-a[j+i+1]);


if(m<=0){
    break;
}if(a[j+i]==a[j+i+1]){
    z++;
}

if(z>v){
    v=z+0;
}
}
}






//cd /home/noi_dlu/crystal
//g++ crystal.cpp -o crystal

if(m<0)
{
    v--;
}
cout<<v+1;
//fclose(stdin);
//fclose(stdout);
    return 0;
}