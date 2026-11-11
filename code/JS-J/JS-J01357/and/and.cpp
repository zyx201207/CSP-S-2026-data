#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,e[200000];
cin>>a>>b;
int maxn=0;
int c=0,d=0;
for(int i=0;i<a;i++){
    cin>>e[i];
}while(c<a-1){
while(d<a){
 if((e[c]&e[d])>maxn)maxn=(e[c]&e[d]);d++;
}c++;d=c+1;
}cout<<maxn;
return 0;}
