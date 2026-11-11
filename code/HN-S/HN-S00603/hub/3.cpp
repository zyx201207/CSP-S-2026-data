#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
int main()
{
    freopen("1.in","w",stdout);
    timeval T;gettimeofday(&T,NULL);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    mt19937_64 rd(T.tv_sec*1000000+T.tv_usec);
    cout<<"0 "<<3<<'\n';
    auto work=[&](int n)
    {
        cout<<n<<' '<<rd()%20+1<<'\n';
        auto f=[&](int l,int r){return rd()%(r-l+1)+l;};
        for(int i=1;i<n;i++) cout<<i-1<<' '<<i+1<<'\n';
    };
    work(4000),work(4000),work(2000);
    return 0;
}