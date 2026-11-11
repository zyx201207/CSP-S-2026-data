#include<bits/stdc++.h>
using namespace std;
string s{};
int n;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    while(n--)
    {
        long long x;
        string a;
        scanf("%lld",&x);
        cin>>a;
        for(int i = 1;i<=x;i++)
        {
            s+=a;
        }
    }
    long long i = 0,j = s.size()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
            ans++;
        i++;
        j--;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
