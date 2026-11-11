#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a=0,b=0;
	int get1=1,get2=1,get3=1,get4=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		get1=0;
		get2=0;
		get3=0;
	}
	else{
        for(int i=0;i<s1.size();i++)
        {

            if(s1[i]>='0'&&s1[i]<='9')
            {
                a+=s1[i];
            }
             if(s2[i]>='0'&&s2[i]<='9')
            {
                a+=s1[i];
            }
        }
        if(a!=b)
        {
            get2=0;
            get3=0;
        }
        else{
            for(int i=0;i<s1.size();i++)
            {

                if(!((s1[i]>='A'&&s1[i]<='C')&&(s2[i]>='A'&&s2[i]<='C')||(s1[i]>='D'&&s1[i]<='F')&&(s2[i]>='D'&&s2[i]<='F')))
                {
                    get3=0;
                }
            }
        }
	}
	for(int i=0;i<s1.size();i++)
    {

        if(!((s1[i]=='A'&&s2[i]=='B')||(s2[i]=='A'&&s1[i]=='B')||(s1[i]=='A'&&s2[i]=='C')||(s2[i]=='A'&&s1[i]=='C')||(s1[i]=='B'&&s2[i]=='C')||(s2[i]=='B'&&s1[i]=='C')||(s1[i]=='D'&&s2[i]=='F')||(s2[i]=='D'&&s1[i]=='F')))
        {
            get4=0;
        }
    }

    cout<<get1<<get2<<get3<<get4;
	return 0;
}
