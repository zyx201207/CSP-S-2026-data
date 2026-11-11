#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
const int N=210;
int a[N];
int main()
{
    freopen("1.in","w",stdout);
    timeval T;gettimeofday(&T,NULL);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    mt19937_64 rd(T.tv_sec*1000000+T.tv_usec);
    int t=100;
    cout<<"0 "<<t<<'\n';
    while(t--)
    {
        int n=rd()%100+1,v=1e9;
        for(int i=1;i<=n;i++) a[i]=rd()%v+1;
        sort(a+1,a+1+n),n=unique(a+1,a+1+n)-a-1;
        cout<<n<<' '<<rd()%v+1<<'\n';
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}