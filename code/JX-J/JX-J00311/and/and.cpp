include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,a[200005],d=0,h,h1,h2,h_,h_z=0,j=0;
cin>>n>>m;
for(int i=0;i<n;i++){
cin>>a[i];
d=max(d,a[i]);
}
if(m==1){
cout<<d;
}else{
d=0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
h1=0,h2=0,h_=0;
h=a[i];
while(h>0){
h1*=10;
h1+=h%2;
h/=2;
}
h=a[j];
while(h>0){
h2*=10;
h2+=h%2;
h/=2;
}
for(int k=0;k<18;k++){
if(h1%10==1 && h2%10==1){
h_+=100000000000000000;
}
h_/=10;
}
h_z=max(h_,h_z);
}
}
while(h_z>0){
j*=2;
j+=h_z%10;
h_z/=10;
}
cout<<j;
}
fclose(stdin);
fclose(stdout);
return 0;
}
