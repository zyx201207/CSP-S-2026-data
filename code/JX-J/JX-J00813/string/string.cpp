#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long cnt=0;
    int n;
    cin>>n;
    int a;
    char c;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    int l=s.size()-1;
    for(int i=0;i<(s.size()+1)/2;i++)
    {
        if(s[i]!=s[l]){
            cnt++;
        }
        l--;
    }
    cout<<cnt;
    return 0;
}
