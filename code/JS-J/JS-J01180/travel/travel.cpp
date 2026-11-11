#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=b-1;i>=a;i--)
string c1,c2,s1,s2;
int num1,num2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
    if(s1[2]>='A'&&s1[2]<='C')num1=1;
    else num1=2;
    if(s2[2]>='A'&&s2[2]<='C')num2=1;
    else num2=2;
    if(num1!=num2)cout<<"00";
    else{
        cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
        if(num1==2){
            if(s1[2]=='D'&&s2[2]=='F')cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
            else if(s2[2]=='D'&&s1[2]=='F')cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
            else cout<<0;
        }
        else{
            if(abs((int)s1[2]-(int)s2[2])==1)cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]);
            else cout<<0;
        }
    }
    cout<<endl;
    return 0;
}
