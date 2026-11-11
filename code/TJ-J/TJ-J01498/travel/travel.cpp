#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string fi;
    string se;
    string th;
    string fo;
    cin>>fi;
    cin>>se;
    cin>>th;
    cin>>fo;
    if(fi==th)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(se[0]==fo[0]&&se[1]==fo[1])
    {
        cout<<1; 
    }
    else
        {
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    char wei=se[2];
    char wei2=fo[2];
    if(wei=='A'||wei=='B'||wei=='C'&&wei2=='A'||wei2=='B'||wei2=='C')
    {
        cout<<1;
    }
    else if(wei=='D'||wei=='F'&&wei2=='D'||wei2=='F')
    {
        cout<<1;
    }
    else{
	
        cout<<0;
        cout<<0;
        return 0;
    }
    int shu=abs(wei-wei2);
    if(wei<'D'&&shu==1)
    {
        cout<<1;
    }
    else if(wei>='D'&&shu==2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
return 0;
}
