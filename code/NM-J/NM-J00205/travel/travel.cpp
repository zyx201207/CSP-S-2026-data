#include <iostream>
#include <string>
using namespace std;

int n[100];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<13;i++)
    {
        cin>>n[i];
    }
    if(n[1]-'0'==n[6]-'0')
    {
        cout<<1;

    }
    else
    {

        cout<<0;
    }
    if(n[3]-'0'==n[8]-'0')
    {
        cout<<1;

    }
    else{
        cout<<0;
    }
        if((n[4]=='A'&&n[9]=='B')||(n[4]=='A'&&n[9]=='C')||(n[4]=='B'&&n[9]=='C')||(n[4]=='B'&&n[9]=='A')||(n[4]=='C'&&n[9]=='B')||(n[4]=='C'&&n[9]=='A')||(n[4]=='D'&&n[9]=='F')||(n[4]=='F'&&n[9]=='D'))
    {
        cout<<1;

    }
    else{
        cout<<0;
    }
    if((n[4]=='A'&&n[9]=='B')||(n[4]=='B'&&n[9]=='C')||(n[4]=='B'&&n[9]=='A')||(n[4]=='C'&&n[9]=='B')||(n[4]=='C'&&n[9]=='A')||(n[4]=='D'&&n[9]=='F')||(n[4]=='F'&&n[9]=='D'))
    {
        cout<<1;

    }
    else{
        cout<<0;
    }
    return 0;
}
