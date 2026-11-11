#include<bits/stdc++.h>
using namespace std;

string s[200001];
int ans=0,n,m;
bool cmp(string s1,string s2){
    return s1>s2;
}

void qer(int x,int id){
    int l=1073741824;
    while(l)
    {
        if(l>x)
        {
            s[id]+='0';
        }
        else
        {
            s[id]+='1';
            x-=l;
        }
        l/=2;
    }
}

int js(int x){
    x=30-x+1;int l=1;
    for(int i=1;i<=x;i++)
    {
        l*=2;
    }
    return l;
}

void dfs(int dep){
    if(dep>=30||n<m) return ;
    int id=-1;
    for(int i=0;i<30-dep;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(s[j][i]=='1') cnt++;
        }
        if(cnt>=m)
        {
            id=i+dep+1;
            break;
        }
    }
    if(id==-1)
    {
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        s[i].erase(0,id-dep);
    }
    sort(s+1,s+n+1,cmp);
    for(int i=n;i>=1;i--)
    {
        if(s[i][0]=='0') n--;
    }
    ans+=js(id+1);
    dfs(id);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) s[i]="";
    int a;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        qer(a,i);
    }
    dfs(-1);
    cout<<ans;
    return 0;
}
