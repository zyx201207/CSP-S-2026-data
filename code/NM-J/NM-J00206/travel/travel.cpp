#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main(){
preopen("member,in","r",in);
preopen("member,out","w",out);
int n,m,a,b;
cin>>n>>m>>a>>b;
for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(a[i]==b[i]&&a[j]==b[j]&&n[i]==b[i]&&n[j]==b[j]){
cout<<"1111";
}
}
}
for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(a[i]!=b[i]&&a[j]!=b[j]&&n[i]!=b[i]&&n[j]!=b[j]){
cout<<"0000";
}
}
}

for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(a[i]=b[i]&&a[j]=b[j]&&n[i]=b[i]&&n[j]!=b[j]||a[i]=b[i]&&a[j]=b[j]&&n[i]!=b[i]&&n[j]=b[j]||a[i]=b[i]&&a[j]!=b[j]&&n[i]=b[i]&&n[j]=b[j]||a[i]!=b[i]&&a[j]=b[j]&&n[i]=b[i]&&n[j]=b[j]){
cout<<"1110";
}
}
}
for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(a[i]=b[i]&&a[j]=b[j]&&n[i]!=b[i]&&n[j]!=b[j]||a[i]=b[i]&&a[j]!=b[j]&&n[i]!=b[i]&&n[j]=b[j]||a[i]!=b[i]&&a[j]!=b[j]&&n[i]=b[i]&&n[j]=b[j]||a[i]!=b[i]&&a[j]=b[j]&&n[i]=b[i]&&n[j]!=b[j]){
cout<<"1100";
}
}
}
for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(a[i]=b[i]&&a[j]!=b[j]&&n[i]!=b[i]&&n[j]!=b[j]||a[i]!=b[i]&&a[j]!=b[j]&&n[i]!=b[i]&&n[j]=b[j]||a[i]!=b[i]&&a[j]!=b[j]&&n[i]=b[i]&&n[j]!=b[j]||a[i]!=b[i]&&a[j]=b[j]&&n[i]!=b[i]&&n[j]!=b[j]){
cout<<"1000";
}
}
}
return 0;
}
