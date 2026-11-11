#include<bits/stdc++.h>
using namespace std;
void Compare(string S)
{
    int cnt=0;
    int len=S.length();
    string S2="";
    for(int i=len-1;i>=0;i--)
    {
    	S2+=S[i];
	}
    for(int i=0;i<len;i++)
    {
        if(S[i]!=S2[i])
        {
            cnt++;
        }
    }
    cout<<cnt/2;
}
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        string b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    Compare(s);
    return 0;
}