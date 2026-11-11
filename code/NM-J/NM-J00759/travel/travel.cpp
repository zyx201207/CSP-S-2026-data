#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long r,x;
    //vector<string> rnum;
	//vector<string> xnum;
	string rnum,xnum;
    cin>>r>>rnum>>x>>xnum;
    //rnum.push_back(o);
   // xnum.push_back(p);
    if(r==x)
    {
        cout<<1;
        if(rnum[0]==xnum[0] && rnum[1]==xnum[1])
        {
            cout<<1;
            if((int(rnum[2]-'0')<int('D'-'0') && int(xnum[2]-'0')<int('D'-'0')) || (int(rnum[2]-'0')>=int('D'-'0') && int(xnum[2]-'0')>=int('D'-'0')))
            {
                cout<<1;
                if(int(rnum[2]-'0')+1==int(xnum[2]-'0') || int(rnum[2]-'0')-1==int(xnum[2]-'0'))
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
            else
                cout<<0<<0<<endl;
        }
        else
            cout<<0<<0<<0<<endl;
    }
    else
        cout<<0<<0<<0<<0<<endl;
    return 0;
}
