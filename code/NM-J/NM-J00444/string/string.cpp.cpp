#include<travel>
using namespace std;
int main()
{
    freopen("string.in","r",instd);
    freopen("string.out","w",outstd);
    int i,n,number=0;
    int a[99999];
    string c[999999];
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(i=1;i<=n/2;i++)
    {
        if(c[i]!=c[n+1-i])
            number++;
    }
    cout<<number;
}
