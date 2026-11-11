#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1;int z1;char l1;
    cin>>n1>>z1>>l1;
    int n2;int z2;char l2;
    cin>>n2>>z2>>l2;
    int t1=0,t2=0,t3=0,t4=0;

    if  (n1!=n2){
        cout<<t1<<t2<<t3<<t4;
        return 0;
    }else{
        t1=1;
    }
    if(z1!=z2){
        t2=0;
    }else{
        t2=1;
    }
    if (l1==l2){
        t3=1;
    }else{
        t3=0;
    }
    if (int(l1)+1==int(l2) || int(l2)+1==int(l1)){
        t4=1;
    }else{
        t4=0;
    }
    cout<<t1<<t2<<t3<<t4;
    return 0;
}
