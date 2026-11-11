#include<iostream>
#include<string>

using namespace std;

string a_cr,b_cr;
string a_pl,b_pl;
bool s_cr,s_ln,s_sd,s_tc;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a_cr>>a_pl>>b_cr>>b_pl;

    if(a_cr==b_cr)s_cr=1;
    if(a_pl[0]==b_pl[0]&&a_pl[1]==b_pl[1]&&s_cr)s_ln=1;
    if(((a_pl[2]<='C'&&b_pl[2]<='C')||(a_pl[2]>='D'&&b_pl[2]>='D'))&&s_ln)s_sd=1;
    if(s_sd)
    {
        if(a_pl[2]>='D'&&b_pl[2]>='D')s_tc=1;
        if(a_pl[2]=='A'&&b_pl[2]=='B')s_tc=1;
        if(a_pl[2]=='B'&&b_pl[2]=='A')s_tc=1;
        if(a_pl[2]=='B'&&b_pl[2]=='C')s_tc=1;
        if(a_pl[2]=='C'&&b_pl[2]=='B')s_tc=1;
    }

    cout<<s_cr<<s_ln<<s_sd<<s_tc;

    return 0;
}