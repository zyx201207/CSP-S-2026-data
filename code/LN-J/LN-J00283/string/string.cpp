#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    string s;
    cin>>a;
    for (int i=0;i<a;i++)
    {
        long long num;char c;
        cin>>num>>c;
        for (long long j=0;j<num;j++)
            s+=c;
    }

    long long l = 0,r = s.size()-1;
    long long result = 0;
    while(l!=r)
    {
        if (s[l]!=s[r]) result++;
        l++;r--;
    }
    cout<<result;
    return 0;
}
