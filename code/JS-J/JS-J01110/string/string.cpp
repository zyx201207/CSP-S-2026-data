#include<bits/stdc++.h>
using namespace std;
#define intt long long
const int MAXN=200005;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt1=0,cnt2=0,ans=0;
    cin>>n;
    vector<pair<int,char>>a,v1,v2;
    for(int i=0;i<n;i++)
    {
        int n;
        char c;
        cin>>n>>c;
        a.push_back({n,c});
        cnt1+=n;
    }
    for(int i=0;i<n;i++)
    {
        if(cnt2+a[i].first<=(cnt1/2+0.5))
        {
            cnt2+=a[i].first;
            v1.push_back({a[i].first,a[i].second});
        }
        else if(cnt2<(cnt1/2+0.5)&&cnt2+a[i].first>(cnt1/2+0.5))
        {
            v1.push_back({cnt1/2-cnt2-cnt1%2,a[i].second});
            v2.push_back({cnt2+a[i].first-cnt1/2,a[i].second});
            cnt2+=a[i].first;
        }
        else v2.push_back({a[i].first,a[i].second});
    }
    reverse(v2.begin(),v2.end());
    int b=0,c=0;
    while(1)
    {
        if(v1[b].second!=v2[c].second)
        {
            if(v1[b].first>v2[c].first) ans+=v2[c].first;
            else if(v1[b].first==v2[c].first) ans+=v1[b].first;
            else ans+=v1[b].first;
        }
        if(v1[b].first>v2[c].first)
        {
            v1[b].first-=v2[c].first;
            c++;
        }
        else if(v1[b].first==v2[c].first)
        {
            b++;
            c++;
        }
        else
        {
            v2[c].first-=v1[b].first;
            b++;
        }
        if(b==v1.size()||c==v2.size()) break;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
