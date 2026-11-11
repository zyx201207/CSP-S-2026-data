#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            char tc1=s1[2],tc2=s2[2];
            if((tc1>='D'&&tc2>='D')||(tc1<='C'&&tc2<='C')){
                cout<<1;
                if(tc1=='D'&&tc2=='F'){
                    cout<<1;
                }else if(tc1=='F'&&tc2=='D'){
                    cout<<1;
                }else if(((int)(tc1)-(int)(tc2))==1){
                    cout<<1;
                }else if(((int)(tc2)-(int)(tc1))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
