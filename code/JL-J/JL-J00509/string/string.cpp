#include <bits/stdc++.h>
using namespace std;
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
string a;
char sy;
long long i,n,b[200006],s0,s=0,q0,q;
cin>>i;
for(int w=1;w<=i;w++){
    cin>>n>>sy;
    b[w]=n;
    a+=sy;
    s+=n;
}
s0=s;
for(q0=0,q=i;q-q0>0;){
    if(a[q0]==a[q-1]){
        if(b[q0+1]>b[q]){b[q0+1]-=b[q]; b[q]=0; q--; }
        else if(b[q0+1]<b[q]){b[q]-=b[q0+1]; b[q0+1]=0; q0++; }
        else {b[q]=0;b[q0+1]=0;q--;q0++;}
    }
    else if(a[q0]!=a[q-1]){
        if(b[q0+1]>b[q]){s-=b[q]; b[q0+1]-=b[q]; b[q]=0; q--; }
        else if(b[q0+1]<b[q]){s-=b[q0+1]; b[q]-=b[q0+1]; b[q0+1]=0; q0++; }
        else {s-=b[q]; b[q]=0;b[q0+1]=0;q--;q0++;}
        }
}
cout<<s0-s;
return 0;
}
