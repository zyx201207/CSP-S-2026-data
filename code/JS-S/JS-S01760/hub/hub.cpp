#include<bits/stdc++.h>
using namespace std;
int main()

{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c ,t;
    cin>>c>>t;
    if(c==1)
    {
        for(int i=0;i<t;i++)
        {
            int n,k;
            cin>>n>>k;
            if(n==k)
            {
                cout<<"0";
            }
            else 
            {
                cout<<"1";
            }
        }
        
    }
    else if(c==13||c==14)
    {
        int n,k;
        cin>>n>>k;
        int m=(n-1)/2;
        if(k==n)
        {
            cout<<"0";
        }
        else if(k>=m-1)
        {
            cout<<"1";
        }
        else if(k>=m/3)
        {
            cout<<"2";
        }
        else{
            cout<<(m-2)/3;
        }
    }
    else{
        for(int i=0;i<t;i++)
        {
            int n,k;
            cin>>n>>k;
            if(n<=2*k)
            {
                cout<<k/2;
            }
            else{
                cout<<(n-k)/3;
            }
        }
  
    }
    return 0;
}