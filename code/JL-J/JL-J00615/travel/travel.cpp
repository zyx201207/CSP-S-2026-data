include<iostream>
include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout)
    int c1,c2;
    string s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if (c1 == c2)
        cout<<ture;


    if (int(s1[0],s1[1]) == int(s2[0],s2[1]))
        cout<<ture;


    if (s1[2]=="D" || s2[2]=="F")
        cout<<ture;
    else if (s1[2]=="F" || s2[2]=="D")
            cout<<ture;


    if (s1[2]=="A" || s2[2]=="B")
        cout<<ture;
    else if (s1[2]=="B" || s2[2]=="A")
            cout<<ture;
    else if (s1[2]=="B" || s2[2]=="C")
            cout<<ture;
    else if (s1[2]=="C" || s2[2]=="B")
            cout<<ture;
    else if (s1[2]=="A" || s2[2]=="C")
            cout<<ture;
    else if (s1[2]=="C" || s2[2]=="A")
            cout<<ture;
    ;
    return 0;
}
