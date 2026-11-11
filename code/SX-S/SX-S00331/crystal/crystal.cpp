#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,l,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cnt=m;
    for(long long i=1;i<=n;i++)
    {
        while(cnt<(a[i]-a[i-1])*(i-l))
        {
            cnt+=a[i-1]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
        cnt-=(a[i]-a[i-1])*(i-l);
    }
    cout<<ans;
    return 0;
}
/*
14:10          西西弗考场提供vscode了？还装好插件了？真的假的？
14:11          真的！那不爽飞！静态报错检查还是太舒服了！
14:30          开考，分析后暂无头绪，设想DP
~14:40-50      逛了一圈题目回来，想到类双指针+类贪心
14:55          完成编码，调试，大样例全过？对了？总觉得会爆炸
14:57          可恶的西西弗果然挖坑了，大样例大在哪里？
15:03          口胡了一下，应该可以了，但尼玛编码给我注释全变滚木了
*/
