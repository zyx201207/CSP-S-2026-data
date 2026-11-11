#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    string s = "";
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin >>x>>c;
        for(int j = 1;j<=x;j++)
        {
            s+=c;
        }
    }
    //cout<<s<<endl;
    int len = s.size();
    int min_c=1e9;
    //if(len%2!=0)
    //{
   //     int ch=0;
   //     string s1  = s.substr(0,len/2);
   //     string s2 = "";
   //     string s3  = s.substr(len/2+1,len/2);
   //     //cout<<s1<<' '<<s3<<"*";
   //     //cout<<s1 <<'*';
   //     for(int i=s1.size()-1;i>=0;i--)
   //     {
   //         s2+=s1[i];
   //     }
   //     for(int i=0;i<s3.size();i++)
   //     {
   //         if(s3[i] != s1[i])
    //        {
    //            ch++;
    //        }
    //    }
        //cout<<ch<<endl;
    //    min_c = min(min_c,ch);
    //}
    if(len%2==0)
    {
        int ch=0;
        for(int i=0;i<len/2;i++)
        {

            if(i==0)
            {

                if(s[0]!=s[len-1])
                {
                    ch++;
                }
            }
            else{
                if(s[i]!=s[len-i])
                {
                    ch++;
                }
            }
        }
        min_c = min(min_c,ch);
    }
    else
    {
        int ch=0;
        for(int i=0;i<len/2;i++)
        {

            if(i==0)
            {

                if(s[0]!=s[len-1])
                {
                    ch++;
                }
            }
            else{
                if(s[i]!=s[len-i])
                {
                    ch++;
                }
            }
        }
        min_c = min(min_c,ch);
    }
    cout<<min_c;
    return 0;
}
