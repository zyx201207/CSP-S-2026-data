#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
int a;
cin>>a;
int s,k=0,h=0,y=0,r=0;
char d,f[10000];
for(int i=0;i<a;i++){
    cin>>s>>d;
    h+=s;
    for(int j=0;j<s;j++){
        f[k]=d;
        k++;
    }
}
int a1=h/2+1;
char a2[100000],a3[1000000];
for(int i=0;i<=a1-1;i++){
    a2[i]=f[i];
}
for(int i=h-1;i>=a1;i--){
    a3[r]=f[i];
    r++;
}

for(int i=0;i<=a1;i++){
    if(a2[i]!=a3[i]){
        y++;
    }
}

cout<<y-1;
    return 0;
}
