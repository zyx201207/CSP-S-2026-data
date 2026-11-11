#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1<<endl;
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            cout<<1<<endl;
            if((s2[2]<='C'&&s4[3]<='C')||(s2[2]>'C'&&s4[2]>'C')){
                cout<<1<<endl;
                if(int(s2[2])-int(s4[2])==1||int(s2[2])-int(s4[2])==-1){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else{
                cout<<0<<endl;
                cout<<0<<endl;
            }
        }
        else{
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
        }
    }
    else{
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }
}
