#include<bits/stdc++.h>
using namespace std;
int getLieId(char lie)
{

    if(lie=='A') return 1;
    if(lie=='B') return 2;
    if(lie=='C') return 3;
    if(lie=='D') return 4;
    if(lie=='F') return 5;
}
int getCe(int lieId)
{
    if(lieId<=3) return 1;
    else return 2;
}
bool isNearInSameCe(int lieId1,int lieId2)
{
    if(lieId1-lieId2==1 || lieId2-lieId1==1) return true;
    return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    string pai1;
    pai1=s1[0];
    pai1+=s1[1];
    string pai2;
    pai2=s2[0];
    pai2+=s2[1];

    char lie1=s1[2],lie2=s2[2];
    int lieId1=getLieId(lie1),lieId2=getLieId(lie2);

    int ce1=getCe(lieId1),ce2=getCe(lieId2);


    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&pai1==pai2) cout<<1;
    else cout<<0;
    if(c1==c2&pai1==pai2&&ce1==ce2) cout<<1;
    else cout<<0;
    if(c1==c2&pai1==pai2&&ce1==ce2&&isNearInSameCe(lieId1,lieId2)) cout<<1;
    else cout<<0;


    return 0;
}
