#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a,now=0,ans=0;
char b,c[200010];
int main()
{
    //9:10-
    //文件读入输出
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //按题目要求读入并整理字符串
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            now++;
            c[now]=b;
        }
    }
    //计算ans的值
    for(int i=1;i<=now/2;i++)
    {
        if(c[i]!=c[now+1-i])    ans++;
    }
    cout<<ans<<endl;
    return 0;
}
