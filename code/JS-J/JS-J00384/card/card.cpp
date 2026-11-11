#include<iostream>
#include<set>
#include<queue>
#include<fstream>
const int maxn=2e5+5;
std::set<int> cnt[3005];
std::deque<int> l[maxn];
int a[maxn];
int ans[maxn];
void add(int i,int shunbian)
{
    if(cnt[i].empty()) return;
    for(auto it=cnt[i].begin();it!=cnt[i].end();it++)
    {
        ans[*it]++;
        cnt[shunbian].insert(*it);
    }
}
int main()
{
    std::freopen("card.in","r",stdin);
    std::freopen("card.out","w",stdout);
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        int target;
        if(l[a[i]].empty())
        {
            target=i+1;
            ans[a[i]]++;
        }
        else
            target=l[a[i]].front();
        add(target,i);
        l[a[i]].push_front(i);
        cnt[i].insert(a[i]);
    }
    /*for(int i=1;i<=n;i++)
    {
        for(auto it=cnt[i].begin();it!=cnt[i].end();it++)
        {
            std::cout<<*it<<" ";
        }
        std::cout<<"\n";
    }*/
    for(int i=1;i<=m;i++)
        std::cout<<ans[i]<<" ";
    return 0;
}
