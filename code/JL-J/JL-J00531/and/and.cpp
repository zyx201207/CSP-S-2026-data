
#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,q[2000],m[2000],z;
cin>>a>>b;
for(int i=0;i<a;i++){
cin>>q[i];}
for(int i=0;i<a;i++){
m[i]=q[i] and q[i+1];
}
z=m[0];
for(int i=0;i<a;i++){
if(m[i]>m[i+1])
z=m[i];
else
    z=m[i+1];}
cout<<z;
return 0;}
