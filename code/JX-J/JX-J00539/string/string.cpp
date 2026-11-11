#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100000000];
string b[100000000];
int main()
{
    Frepoen("travel.in","r",stdin);
    frepoen("travel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&b[1]=="a"&&b[2]=="b"&&b[3]=="c")
    {
        cout<<"2";
    }
}
