#include<bits/stdc++.h>
using namespace std;
int a[2001];
int main()
{freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int c,b;
cin>>c>>b;
for(int i=1;i<=c;++i)
{
    int j=i;
    cin>>a[i];
    while(a[j]>a[j-1]&&j>1)
    {
        swap(a[j],a[j-1]);
        j--;
    }
}
cout<<a[1]<<endl;
return 0;
}
