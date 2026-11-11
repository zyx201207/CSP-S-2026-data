#include <bits/stdc++.h>
using namespace std;
bool a[5];
char c1,s1,c2,s2;
char sa[4],sb[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[1]=true;
    }
    for(int i=0;i<3;i++){
        sa[i]=s1[i];
        sb[i]=s2[i];
    }
    for(int i=0;i<2;i++){
        if(sa[i]==sb[i]){
            a[i+1]=true;
        }
        else{
            a[i+1]=false;
        }
    }
    if(sa[2]-1==sb[2] || sa[2]-1==sb[2]){
        a[3]=true;
    }else{
        a[3]=false;
    }
    for(int i=0;i<=3;i++){
        if(a[i]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
