#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
char to,tp;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string tx1;
    tx1+=s1[0];
    tx1+=s1[1];
    //cout<<tx1<<endl;
    string tx2;
    tx2+=s2[0];
    tx2+=s2[1];
    //cout<<tx2<<endl;
    to=s1[2];
    //cout<<to<<endl;
    tp=s2[2];
    //cout<<tp<<endl;
    if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(tx1==tx2&&c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"){
            cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(((to<='C'&&tp<='C')||(to>='D'&&tp>='D'))&&(tx1==tx2)&&(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16")){
            cout<<'1';

    }
    else{
        cout<<'0';
    }
    if(((to=='A'&&tp=='B')||(to=='B'&&tp=='A')||(to=='B'&&tp=='C')||(to=='C'&&tp=='B')||(to=='D'&&tp=='F')||(to=='F'&&tp=='D'))&&(((to<='C'&&tp<='C')||(to>='D'&&tp>='D')))&&(tx1==tx2&&c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16")){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
    return 0;
}
