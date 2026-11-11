#include <iostream>
#include <string>
using namespace std;
long long n,num,sum;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num >> c;
        sum+=num;
        for(int i=0;i<num;i++)
        {
            s+c;
        }
    }
    long long l=1,r=sum,ans=0;
    while(l<=r)
    {
        if((s[l]-'a')!=(s[r]-'a'))
        {
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
