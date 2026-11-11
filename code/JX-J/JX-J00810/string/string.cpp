#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;


int ans=0;

struct node
{
    int n;
    char ch;
}nodes[N];

int st,bk;
int n,len=0;
/*
bool fd(int x)
{
    while(nodes[st].pre2<len/2)
    {
        if(nodes[st].pre2<=x)st++;
        if(nodes[bk].pre<=x)bk--;
        return nodes[st].ch!=nodes[bk].ch;
    }
}
*/

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    st=1,bk=n+1;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>nodes[i].n>>nodes[i].ch;
        len+=nodes[i].n;
    }
    node A[N];
    int cnt=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt+nodes[i].n>len/2)
        {
            A[++tot].n=len/2-cnt,A[tot].ch=nodes[i].ch;
            flag=tot;
            A[++tot].n=cnt+nodes[i].n-len/2-len%2,A[tot].ch=nodes[i].ch;
            cnt=-INT_MAX;
        }
        else A[++tot].n=nodes[i].n,A[tot].ch=nodes[i].ch;
        cnt+=nodes[i].n;
    }/*
    for(int i=1;i<=n+1;i++){
    for(int j=1;j<=A[i].n;j++)cout<<A[i].ch;
    cout<<" ";}*/
    st=1,bk=tot;
    pair<int,char> ya={A[st].n,A[st].ch},yb={A[bk].n,A[bk].ch};
    while(st<=flag&&bk>flag)
    {
        if(ya.second!=yb.second)
        {
            //cout<<ya.second<<yb.second<<endl;
            ans+=min(ya.first,yb.first);
        }  
        int m=min(ya.first,yb.first);
        ya.first-=m;
        yb.first-=m;
        if(ya.first==0)ya={A[++st].n,A[st].ch};
        if(yb.first==0)yb={A[--bk].n,A[bk].ch};
    }
    
    //for(int i=0;i<len/2;i++)if(fd(i))ans++;
    /*
    while(nodes[st].pre2<len/2&&nodes[bk].pre<len/2)
    {
        int x=nodes[st].pre2,y=nodes[bk].pre;
        if(nodes[st].ch==nodes[bk].ch)
        {
            if(x<y)st++;
            else bk--;
            continue;
        }
        if(x<y)
        {
            ans+=x-nodes[bk+1].pre;
            st++;
        }else 
        {
            ans+=y-nodes[st-1].pre2;
            bk--;
        }
    }*/
    cout<<ans;

    return 0;
}