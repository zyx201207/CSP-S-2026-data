#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string q,w,z,x;
    int s,d;
    bool a[4]={0};
    cin>>q>>w>>z>>x;
    if(q[1]==z[1]&&q[0]==z[0])a[0]=1;
    if(w[1]==x[1]&&w[0]==x[0]&&a[0]==1)a[1]=1;
    if(w[2]-'a'>2)s=2;
    else {s=1;}
     if(x[2]-'a'>2)d=2;
    else {d=1;}
    if(a[1]==1&&s==d)a[2]=1;
    if(w[2]-'a'>x[2]-'a'){
            if(a[2]==1&&w[2]-x[2]==1)a[3]=1;
            }
    else{
            if(a[2]==1&&x[2]-w[2]==1)a[3]=1;}
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;

}
