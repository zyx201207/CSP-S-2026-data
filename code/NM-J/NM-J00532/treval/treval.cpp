#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
        freopen("treval.in","r",stdin);
        freopen("treval.out","w",stdout);

        cin>>c1>>s1>>c2>>s2;
        if(c1!=c2){cout<<0000;fclose(stdin);fclose(stdout);return 0;}
                        else    {
                                                if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){cout<<0000;fclose(stdin);fclose(stdout);return 0;}
                                                else cout<<1;
                                        }
        if(s1==s2){cout<<000;return 0;}
        else cout<<11;

        if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="A")||(s1=="B"&&s2=="C")||(s1=="C"&&s2=="B")||(s1=="D"&&s2=="F")||(s1=="F"&&s2=="D")){cout<<11;return 0;}
        else {cout<<00;return 0;}

        fclose(stdin);
        fclose(stdout);

        return 0;
}

