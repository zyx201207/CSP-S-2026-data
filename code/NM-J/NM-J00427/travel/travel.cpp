#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int m,n,x,y;
    char p,q;
    m=b[0]-'0';
    n=d[0]-'0';
    x=b[1]-'0';
    y=d[1]-'0';
    p=b[2];
    q=d[2];
    if(a==c)
    {
        if(m==n and x==y)
        {
            if(p<='C' and q<='C' or p>'C' and q>'C')
            {
                if(p+1==q or p-1==q)
                {
                	cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
            }
            else
			{
				cout<<"1100";
			}
        }
        else
        {
            cout<<"1000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
