#include <bits/stdc++.h>

using namespace std;

struct node{
    int a;
    char c;
};

int n;
long long ans;

node st[200005];

void countt(int i,int j)
{
    if(i>=j)
    {
        return ;
    }
    if(st[i].c==st[j].c)
    {
        if(st[i].a<st[j].a)
        {
            st[j].a-=st[i].a;
            countt(i+1,j);
            return ;
        }
        else if(st[i].a>st[j].a)
        {
            st[i].a-=st[j].a;
            countt(i,j-1);
            return ;
        }
        else
        {
            countt(i+1,j-1);
            return ;
        }
    }
    else
    {
        if(st[j].a>=st[i].a)
        {
            ans+=st[i].a;
            st[j].a-=st[i].a;
            countt(i+1,j);
            return ;
        }
        else
        {
            ans+=st[j].a;
            st[i].a-=st[j].a;
            countt(i,j-1);
            return ;
        }
    }
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
     	cin>>st[i].a>>st[i].c;
	}
	countt(1,n);
	cout<<ans;
    return 0;
}
