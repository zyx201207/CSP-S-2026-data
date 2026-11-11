#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[300001];
int t[300001][40];
vector<int> ha[40];
vector<int> mme;
void bui(int s,int nod)
{
    int bac=0;
    while(s>0)
    {
        t[nod][bac]=s%2;
        if(s%2==1)
            ha[bac].push_back(nod);
        s/=2;
        bac++;
    }
}
void lur(int nod)
{
    for(int i=0;i<=31;i++)
        if(t[nod][i]==1)
            ha[i].push_back(nod);
}
void st(int no)
{
    mme.clear();
    for(int i=0;i<ha[no].size();i++)
        mme.push_back(ha[no][i]);
    for(int i=0;i<=31;i++)
        ha[i].clear();
    if(mme.size()==m)
    {
        int ans=num[mme[0]];
        for(int i=1;i<mme.size();i++)
            ans=(ans&num[mme[i]]);
        cout<<ans;
        return;
    }
    for(int i=0;i<mme.size();i++)
        lur(mme[i]);
    bool bj=false;
    for(int i=no-1;i>=0;i--)
        if(ha[i].size()>=m){
            st(i);
            bj=true;
            break;
        }
    if(!bj)
    {
        int ans=num[mme[0]];
        for(int i=1;i<mme.size();i++)
            ans=(ans&num[mme[i]]);
        cout<<ans;
        return;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   bool bj=false;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
        cin>>num[i];
        bui(num[i],i);
   }
    for(int i=31;i>=0;i--)
        if(ha[i].size()>=m){
            st(i);
            bj=true;
            break;
        }
    if(!bj)
        cout<<0;
    fclose(stdin);
   fclose(stdout);
   return 0;
}
