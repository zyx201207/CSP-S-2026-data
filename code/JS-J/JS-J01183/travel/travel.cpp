#include<bits/stdc++.h>
using namespace std;
int a[5][5]={{1,1,1,0,0},{1,1,1,0,0},{1,1,1,0,0},{0,0,0,1,1},{0,0,0,1,1}};
int b[5][5]={{0,1,0,0,0},{1,0,1,0,0},{0,1,0,0,0},{0,0,0,0,1},{0,0,0,1,0}};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
            cout<<"1";
  //          cout<<"\n"<<s1[2]-'A'<<" "<<s2[2]-'A'<<"\n";
            if(a[s1[2]-'A'][s2[2]-'A']==1){
                cout<<"1";
                if(b[s1[2]-'A'][s2[2]-'A']==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
