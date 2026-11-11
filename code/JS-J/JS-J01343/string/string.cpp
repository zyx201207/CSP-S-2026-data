#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin >> n;
    int num;
    string c;
    for(int i=1;i<=n;i++)
    {
        cin >> num >> c;
        for(int j=1;j<=num;j++)
        {
            s+=c;
        }
    }
    int l=s.size();
    int mid=l/2;
    int cnt=0;
    for(int i=0;i<mid;i++)
    {
        if(s[i]!=s[l-i-1])
            cnt++;
    }
    cout << cnt;
    return 0;
}
