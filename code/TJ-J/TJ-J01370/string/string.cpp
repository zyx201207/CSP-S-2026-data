#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x,i,shuzi;
    cin>>n;
    cin>>x;
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>i;
        }
        if(i[k]!=i[n])
        {
            shuzi+=1;
        }
    }
    cout<<shuzi;
    return 0;
}
