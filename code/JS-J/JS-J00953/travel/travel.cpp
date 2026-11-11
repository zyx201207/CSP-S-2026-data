#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y;
    string s1,s2;
    cin>>x>>s1>>y>>s2;
    if(x==y){
        cout<<1;
        string t1=s1.substr(0,2);
        string t2=s2.substr(0,2);
        if(t1==t2){
            cout<<1;
            t1=s1.substr(2,1);
            t2=s2.substr(2,1);
            char c1=t1[0];
            char c2=t2[0];
            if((t1=="C"||t1=="B"||t1=="A")&&(t2=="C"||t2=="B"||t2=="A")){
                cout<<1;
                if(t1=="A"&&(t2=="B")){
                    cout<<1;
                }
                else if(t1=="B"&&(t2=="A"||t2=="C")){
                    cout<<1;
                }
                else if(t1=="C"&&(t2=="B")){
                    cout<<1;
                }
                else if(t1=="D"&&(t2=="F")){
                    cout<<1;
                }
                else if(t1=="F"&&(t2=="D")){
                    cout<<1;
                }
                else cout<<0;
            }
            else if((t1=="D"||t1=="F")&&(t2=="D"||t2=="F")){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else {
        cout<<"0000";
    }
    return 0;
}
