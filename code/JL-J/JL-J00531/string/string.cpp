#include<bits/stdc++.h>
using namespace std;
int main(){
string a,x;
int b,c=0,e,r;
cin>>e;
for(int z=0;z<e;z++){
    cin>>r>>a;
    for(int j=0;j<r;j++){
    x+=a;}}
b=x.size();
for(int i=0;i<b/2;i++){
    if(x[i]==x[b-1])
        continue;
    else
        c++;
    b--;}
    cout<<c;
}
