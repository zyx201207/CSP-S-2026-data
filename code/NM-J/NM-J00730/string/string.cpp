#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char a;
    char q[200005],w[200005];
    int s,d=0,f,z=0;
    cin>>s;
    for(int i=0;i<s;i++){
      cin>>f>>a;
      for(int j=0;j<f;j++){
                q[z]=a;
      z++;
    }}
     for(int i=0;i<z;i++){
        w[z-i]=q[i];
     }
    for(int i=0;i<s;i++){
        if(w[i]!=q[i])d++;
    }
    cout<<d;
    return 0;}
