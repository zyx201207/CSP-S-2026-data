#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[4]={0,0,0,0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char t1=s1[2],t2=s2[2];
    if(t1<t2)swap(t1,t2);
    if(c1==c2){
        a[0]=1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            a[1]=1;
            if(!(t1>='D' && t2<='C')){
                a[2]=1;
                if(t1=='F' && t2=='D')a[3]=1;
                if(t1=='C' && t2=='B')a[3]=1;
                if(t1=='B' && t2=='A')a[3]=1;
            }
        }
    }
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
