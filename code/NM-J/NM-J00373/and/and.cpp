#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num1[1000000],num2[1000000];
    int c1,c2=0;
    cin>>n>>m;
    for(int i=0;i<=n;i++)cin>>num1[i];

    for(int i=0;i<=n;i++)if(num1[i]>=c1)c1=num1[i];
    cout<<c1;

    fclose(stdin);
    fclose(stdout);
return 0;
}
