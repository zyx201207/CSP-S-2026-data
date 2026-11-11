#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1;
    string s2;
    string c1;
    string c2;
    string s;
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=18;i++)
    {
        if(c1[i]=='01'||c1[i]=='16'||c2[i]=='01'||c2[i]=='16')
        {
            s[i]+=0;
        }
        else if(c1==c2)
        {
            s[i]+=1;
        }
        for(int a=0;a<3;a++)
        {
            if(s1[i]==s2[i]&&s1[i+1]==s2[i+1])
            {
                s[i]+=1;
            }
            else s[i]+=0;
       }
       for(int z='A';z<='F';z++)
       {
            if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'&&s2[i]=='A'||s2[i]=='B'||s2[i]=='C')
            {
                s[i]+=1;
            }
            else if(s1[i]=='D'||s1[i]=='F'&&s2[i]=='D'||s2[i]=='F')
            {
                s[i]+=1;
            }
            else s[i]+=0;
        }
        for(int f='A';f<='C';f++)
        {
            if(s1[i]=='A'&&s2[i]=='B') s[i]+=1;
            else if(s1[i]=='B'&&s2[i]=='C') s[i]+=1;
            else s[i]+=0;
        }
            cout<<s[i];
    }

    fclose(stdin);
    fclose(stdout);
}
