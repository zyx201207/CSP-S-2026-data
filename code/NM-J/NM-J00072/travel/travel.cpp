#include<bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
struct sit{
    int che;
    int pai;
    char zuo;
};
sit a,b;
int main()
{
	IOS;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a.che>>a.pai>>a.zuo>>b.che>>b.pai>>b.zuo;
    if(a.che==b.che)
    {
        cout<<1;
        if(a.pai==b.pai)
        {
            cout<<1;
            switch(a.zuo)
            {
            case 'A':
                if(b.zuo=='B'||b.zuo=='C')cout<<1;
                else
                {
                    cout<<"00";
                    break;
                }
                if(b.zuo=='B')cout<<1;
                else cout<<0;
                break;
            case 'B':
                if(b.zuo=='A'||b.zuo=='C')cout<<11;
                else cout<<"00";
                break;
            case 'C':
                if(b.zuo=='B'||b.zuo=='A')cout<<1;
                else
                {
                    cout<<"00";
                    break;
                }
                if(b.zuo=='B')cout<<1;
                else cout<<0;
                break;
            case 'D':
                if(b.zuo=='F')cout<<11;
                else cout<<"00";
                break;
            case 'F':
                if(b.zuo=='D')cout<<11;
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
	return 0;
}
