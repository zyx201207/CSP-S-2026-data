#include<bits/stdc++.h>
using namespace std;
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int main(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        for(int i=1;i<=18;i++){
            if(s1[i]==s2[i]){
                cout<<"1";
                for(int j="A";j<="F";j++){
                    if(s1[j]=="D"&&s2[j]=="F"){
                            cout<<"1";
                        if(s1[j]==s2[j+1]||s2[j]==s1[j+1]){
                            cout<<"1";
                        }
                        else(){
                            cout<<"0";
                        }
                    }
                    else if(s1[j]=="A"&&s2[j]=="B"||s1[j]=="B"&&s1[j]=="C"){
                    cout<<"1";
                    }
                    else(){
                    cout<<"0"
                    }
                }
            }
            else(){
                cout<<"0";
            }
        }
    }
    else(){
        cout<<"0000";
    }
    return 0;
}
