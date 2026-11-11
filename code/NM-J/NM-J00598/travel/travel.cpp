#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,a1,b1;
    int ans1,ans2,ans3,ans4;
    cin>>c1>>c2>>s1>>s2;
    if(c1=="01"||c1=="16"||c2=="01"||c2=="16")
    {
        ans1=0;
    }
    if(c1==c2)
    {
       ans1=1;
    }else
    {
       ans1=0;
    }
    for(int i=0;i<2;i++)
    {
         if(s1[i]!='0')
         {
             a1+=s1[i];
         }
         if(s2[i]!='0')
         {
            b1+=s2[i];
          }
    }
    int c=s1[2];
    int d=s2[2];
    bool e=a1==b1;
    if(a1==b1)
    {
         ans2=1;
    }

    bool e1=(c<='C'&&d<='C');
    bool e2=(c>'C'&&c<='F');
    bool e3=(d>'C'&&d<='F');
    bool e4=(e2&&e3);
    bool e5=e1||e4;
    if(e5&&ans2==1&&ans1==1) 
    {
       ans3=1;
    }
    bool o1=(c=='A'&&d=='B');
    bool o2=(c=='B'&&(d=='A'||d=='C'));
    bool o3=(c=='C'&&d=='B');
    bool o4=(c=='D'&&d=='F');
    bool o5=(c=='F'&&d=='D');
    bool o6=o1||o2||o3||o4||o5;
    bool o7=o6&&ans2==1;
    if(o7)
    {
    	ans4=1;
	}
    bool e9=(c<='C'&&d<='C');
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
	
