#include<iostream>
using namespace std;
int main()
{
    //freopen("travel.in","r",stdin)
    //freopen("travel.out","w",stdout)
    string c1,s1,c2,s2,D="D",F="F",A="A",B="B",C="C";
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1])
    {
        if(c1[2]==c2[2])
        {
            cout<<"1";
            if(s1[1]==s2[1]||s1[2]==s2[2])
            {
                cout<<"1";
                if(s1[3]==D[1]||s1[3]==F[1])
                {
                    if(s2[3]==D[1]&&s2[3]==F[1])
                    {
                        cout<<"10";
                    }
                    else
                    {
                        cout<<"00";
                    }
                }
                else
                {
                    if(s1[3]==A[1]||s1[3]==B[1])
                    {
                        if(s2[3]==A[1]||s2[3]==B[1])
                        {
                            cout<<"10";
                        }
                    }
                    else
                    {
                        if(s2[3]==A[1]||s2[3]==B[1])
                        {
                            cout<<"10";
                        }
                        else
                        {
                            cout<<"00";
                        }
                    }
                }
            }
            else
            {
                cout<<"000";
            }
        }
    }
    else
    {
        cout<<"0000";
    }


    return 0;

}
