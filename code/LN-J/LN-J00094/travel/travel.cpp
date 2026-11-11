#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else{
        cout<<"0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
    else{
        cout<<"000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(s1[2]+s2[2]==136||s1[2]+s2[2]==129||s1[2]+s2[2]==130||s1[2]+s2[2]==131&&s1[2]!=67&&s2[2]!=67)
        cout<<"1";
    else{
        cout<<"00";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    if(s1[2]+s2[2]==136||s1[2]+s2[2]==129||s1[2]+s2[2]==131&&s1[2]!=67&&s2[2]!=67)
        cout<<"1";
   else
        cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
