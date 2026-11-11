#include <bits/stdc++.h>
using namespace std;
string s1[28];
string s2[28];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int l1=s1.size();
    int l2=s2.size();
    if(c1==c2)
    {
        cout<<1;
    }
        else
        {
            cout<<0;
        }
        for(int i=1;i<=l1;i++)
        {

            for(int j=1;j<=l2;j++)
            {
                if(i==j)
                {

                    cout<<1;

                }
                else
                {
                    cout<<0;
                }
                if(s1%10=='A'||s1%10=='B'||s1%10=='C'    &&   s2%10=='A|'|s2%10=='B|'|s2%10=='C ' ||s1%10=='D'||s1%10=='F' && s2%10=='D '||s2%10=='f')
                {
                    cout<<1;

                }
                else
                {
                    cout<<0;
                }
                if(s1+1==s2||s1-1==s2)
                {

                    cout<<1;

                }
                else
                {
                    cout<<0;
                }


            }
        }







    return 0;
}
