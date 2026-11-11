#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int l=0;
    int m=0;
    vector <char> q;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        char b;
        cin>>b;
        for(int j=l;j<l+a;j++)
        {

            q.push_back (b);
        }
         l+=a;

    }
    for(int i=0;i<l;i++)
    {
        if(q[i]!=q[l-i-1])
        {
            m++;
        }
    }
    if(m%2==0)
    {
        m=m/2;
    }
    else{
        m=m/2+1;
    }

    cout<< m;
    return 0;
}
