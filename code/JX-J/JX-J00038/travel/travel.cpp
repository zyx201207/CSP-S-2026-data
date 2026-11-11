#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
    freopen("fravel.in","r",stdin);
    freopen("fravel.out","w",stdout);
    for(int i=0;i<4;i++){
        a[i]=1;
        if(i==2){
            a[i]=0;
        }
    }
    int yiu=0,pai=0,xian=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            a[0]=0;
            xian=1;
            break;
        }
    }
    for(int i=0;i<2;i++){
        if(xian==0){
            if(s1[i]!=s2[i]){
                a[1]=0;
                pai=1;
                break;
            }
        }
        else{
            a[1]=0;
            pai=1;
            break;
        }
    }
    for(int i=2;i>=2;i--){
        if(s1[i]>'C'&&s2[i]>'C'||s1[i]<='C'&&s2[i]<='C'&&pai==0){
            a[2]=1;
            yiu=1;
            break;
        }
    }
    for(int i=2;i>=2;i--){
        if(abs(s1[i]-s2[i])!=1||yiu==0){
            a[3]=0;
            break;
        }
    }
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    return 0;
}
