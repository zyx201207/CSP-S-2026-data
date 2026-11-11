#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_1,s_1,c_2,s_2;
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1!=c_2)
        cout<<"0000"<<endl;
    else{
        string r_1="",r_2="";
        r_1+=s_1[0],r_1+=s_1[1];
        r_2+=s_2[0],r_2+=s_2[1];
        if(r_1!=r_2)
            cout<<"1000"<<endl;
        else{
            if((s_1[2]<='C' && s_2[2]<='C') || (s_1[2]>='D' && s_2[2]>='D')){
                int x=s_1[2]-'A'+1,y=s_2[2]-'A'+1;
                if(x>y)
                    swap(x,y);
                if((x==4 && y==6) || (y-x==1 && y!=4))
                    cout<<"1111"<<endl;
                else
                    cout<<"1110"<<endl;
            }
            else
                cout<<"1100"<<endl;
        }
    }
    return 0;
}
