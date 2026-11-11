#include<iostream>
#include<cstring>
using namespace std;

int n;
string s;
int idx,len;
int ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char a;
        cin>>x>>a;
        for(int j=1;j<=x;j++)
        {
            s[idx++]=a;
            len++;
        }
    }
    int l=0,r=len-1;
    while(l<=r)
    {
        if(s[l]!=s[r])
            ans++;
        l++;
        r--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
