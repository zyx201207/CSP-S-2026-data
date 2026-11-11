#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,a[1000001];
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    while(t++){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int b=0,s=0;
    for(int i=2;i<=n;i++){
    s=min(s,a[i],a[i-1])}


    }
    cout<<s<<endl;
    if(s==d){
    cout<<"0"<<endl;
    continue;}
    int q=0,g=a[2],a[1];
    for(int i=3;i<=n;i++){
    if(a[i],a[i-1]!=c){
    q=1;
    break;}
    if(q==0){
    if(d==g&&d<2*g){
    cout<<"0"<<endl;
    continue;
    }
    if(d==2*g){
    for(int i=1;i<=n;i++)
        b++;
    cout<<b<<endl;
    continue;}
    }
    }
    return 0;
    }
