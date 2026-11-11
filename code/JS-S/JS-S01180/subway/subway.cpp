#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int k,c[300]={0},d[300]={0};
};
int ans=1e9;
// y: mu biao zhan dian cnt: suo hua shi jian
void dfs(int n,int m,int a[],Node b[],int x,int y,int cnt,int r,int pre) //r: (suo zai xian lu) -1   x: mu qian zhan dian
{
    if(pre>=n) return;
    if(x==y)
    {
        cnt+=a[y-1]; //cnt+=(zou dao zui zhong zhan ting + zou chu di tie kou de shi jian)
        for(int i=0;i<b[r].k;i++)
            if(b[r].c[i]==y)
            {
                cnt+=b[r].d[i];
                break;
            }
        ans=min(ans,cnt);
        return;
    }
    //mei ci wang xia zuo yi zhan
    //pan duan shi fou ke yi zhuan che
    for(int i=0;i<n;i++)
    {
        if(i==r) continue;
        for(int j=0;j<b[i].k;j++)
            if(b[i].c[j]==x)
                dfs(n,m,a,b,x,y,cnt+b[i].d[j]+b[r].d[j],i,j+1);
    }
    dfs(n,m,a,b,b[r].c[pre+1],y,cnt,r,pre+1);
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int w,n,m,s,q; cin>>w>>n>>m>>s>>q; //n:xian lu shu m:zhan shu d:zui duo xian lu jing guo shu q:ji hua shu
    int a[m];
    for(int i=0;i<m;i++) cin>>a[i]; //mei ge di tie zhan kou dao zhan ting suo xu yao de shi jian
    Node b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i].k;
        for(int j=0;j<b[i].k;j++)
            cin>>b[i].c[j]>>b[i].d[j]; //c[]:di i tiao xian lu suo jing guo de di tie zhan
    }// d[]: cong zhan ting zou dao di c[i] ge zhan tai suo xu yao de shi jian
    while(q--)
    {
        int x,y; cin>>x>>y;
        for(int i=0;i<n;i++)
        {
            int flag=-1e9,t1=0;
            for(int j=0;j<b[i].k;j++)
                if(b[i].c[j]==x)
                {
                    flag=b[i].d[j],t1=j;
                    break;
                }
            if(flag!=-1e9)
                dfs(n,m,a,b,x,y,a[x-1]+flag,i,t1);
        }
        if(ans==1e9) cout<<32<<endl;
        else cout<<ans<<endl; ans=1e9;
    }
    return 0;
}
