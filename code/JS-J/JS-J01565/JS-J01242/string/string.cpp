#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll,char> pii;
const int N=200010;
int n;
ll a[N];
char c[N];
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    deque<pii> q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        q.push_front({a[i],c[i]});
    }
    while(q.size()>=2)
    {
        ll num1=q.front().first;
        char ch1=q.front().second;
        ll num2=q.back().first;
        char ch2=q.back().second;
        q.pop_front();
        q.pop_back();
        if(num1==num2)
        {
            if(ch1!=ch2)
                ans+=num1;
        }
        else if(num1<num2)
        {
            q.push_back({num2-num1,ch2});
            if(ch1!=ch2)
                ans+=num1;
        }
        else
        {
            q.push_front({num1-num2,ch1});
            if(ch1!=ch2)
                ans+=num2;
        }
    }
    cout<<ans;
    return 0;
}

