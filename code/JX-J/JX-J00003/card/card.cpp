#include<bits/stdc++.h>
using namespace std;
int n,m;
int ty[500005];
int ans[500005];
bool bj[500005];
int la[500005];
void force(int nod)
{
    int sta[500005],top=0;
    for(int i=1;i<=m;i++)
        bj[i]=la[i]=0;
    for(int i=nod;i<=n;i++)
    {
        if(la[ty[i]]>0){
            for(int j=1;j<=m;j++)
                if(la[j]<=top&&la[j]>la[ty[i]]&&j!=ty[i])
                    la[j]=-1;
            top=la[ty[i]]-1;
        }
        sta[++top]=ty[i];
        la[ty[i]]=top;
    }
    for(int i=1;i<=top;i++)
        bj[sta[i]]=true;
    for(int i=1;i<=m;i++)
        if(bj[i])
        ans[i]++;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>ty[i];
    for(int i=1;i<=n;i++)
        force(i);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    fclose(stdin);
   fclose(stdout);
   return 0;
}
