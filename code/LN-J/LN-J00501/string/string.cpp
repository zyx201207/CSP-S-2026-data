#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<char>v(1000);
    vector<char>v1(1000);
    int  d,n,e=0,y=0,w=0,l=0;
    cin>>d;
    for(int i=0;i<d;i++)
    {
        cin>>n>>v[0];
        e+=n;
        for(int j=0;j<n;j++)
       {
        v1.push_back(v[0]);
       }
    }
    if(e%2==0)
        y=e/2;
    else
        y=e/2+1;
    for(int i=y;i<e;i++)
    {w+=1;
    if(v1[i]!=v1[i-w])
        l+=1;
    }
    cout<<l;

    return 0;
     }
