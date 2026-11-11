#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a[15];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=2;i<=17;i++){
        if(c1=c2 and c1!=16 and c2!=16){
            a[1]=1;
        }else{
            a[1]=0;
        }
    }
    for(int i=0;i<=18;i++){
        if(s1[1]=s2[1] and s1[2]=s2[2]){

            a[2]=1;

        }else{
            a[2]=0;
        }
        if(s1[1]=s2[1] and s1[2]=s2[2] and s1[3]>='A' and s1[3]<='B' and s2[3]>='A' and s2[3]<='B' ){
            a[3]=1;
        }else if(s1[1]=s2[1] and s1[2]=s2[2] and s1[3]>='D' and s1[3]<='F' and s2[3]>='D' and s2[3]<='F'){
            a[3]=1;
        }else{
            a[3]=0;
        }
        if(s1[1]=s2[1] and s1[2]=s2[2] and s1[3]>='A' and s1[3]<='B' and s2[3]>='A' and s2[3]<='B' and s1[3]+1=s2[3] or s1[3]-1=s2[3]){
            a[4]=1;
        }else if(s1[1]=s2[1] and s1[2]=s2[2] and s1[3]>='D' and s1[3]<='F' and s2[3]>='D' and s2[3]<='F'){
            a[4]=1;
        }else{
            a[4]=0;
        }
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];




    return 0;
}
