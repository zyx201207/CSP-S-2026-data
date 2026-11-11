#include <bits/stdc++.h>
using namespace std;
int s(string a){
    if(a[2]>='D'){
        return 0;
    }
    return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    int a[4]={0,0,0,0};
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0]=1;
        if(s1[0] ==s2[0] and s1[1] == s2[1]){
        a[1]=1;
        if(s(s1)==s(s2)){
            a[2]=1;
            if(s1[2]+1==s2[2] or s2[2]+1==s1[2]){
                a[3]=1;
            }
        }
     }
    }

    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
