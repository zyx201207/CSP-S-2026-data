#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    bool fog;
    bool de;
    bool mei;
    bool heo;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
    fog=1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0])
    {
        de=1;
    }
    else
    {
        de=0;
    }
    if(s1[1]==s2[1])
    {
        mei=1;
    }
    else
    {
        mei=0;
    }
    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C')
    {
        heo=1;
    }
    else
    {
        heo=0;
    }
	cout<<fog<<de<<mei<<heo;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
