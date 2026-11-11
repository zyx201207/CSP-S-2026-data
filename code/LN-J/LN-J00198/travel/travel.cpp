#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[10]={},s1[10]={},c2[10]={},s2[10]={};
    bool a=0,b=0,f=0,d=0;
    cin>>c1>>s1>>c2>>s2;
    if(strcmp(c1,c2)==0){
        cout<<"1";
        a=1;
        if(s1[0]-s2[0]==0&&s1[1]-s2[1]==0){
            cout<<"1";
            b=1;
            if(s1[2]>='A'&&s1[2]<='C'){
                if(s2[2]>='A'&&s2[2]<='C'){
                    cout<<"1";
                    f=1;
                }
            }else{
                if(s2[2]>='D'&&s2[2]<='E'){
                    cout<<"1";
                    f=1;
                }
            }
            if(f){
                if(max(s1[2]-s2[2],s2[2]-s1[2])==1){
                    cout<<"1";
                    d=1;
                }
            }
        }
    }
    if(!a){
        cout<<"0000";
    }
    else if(!b){
        cout<<"000";
    }else if(!f){
        cout<<"00";
    }else if(!d){
        cout<<"0";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
