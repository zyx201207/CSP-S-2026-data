#include<bits/stdc++.h>
using namespace std;
string s;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x,minn=10000,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cin>>a;
        if(x<minn)
            minn=x;
        sum+=x;
    }
    if(n==1)
        cout<<1;
    if(n==2){
        cout<<minn;
    }
    else
        cout<<sum-3;
    return 0;
}

