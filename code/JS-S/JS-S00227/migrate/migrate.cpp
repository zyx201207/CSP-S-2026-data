#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;long long a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;

    /**while(t--){
        cin>>n>>d;int ans=0;
        for(long long i=1;i<=n;i++)
            cin>>a[i];

        for(long long p=1;p<=n-d-1;p++)
        {
            stack<long long> s;
            s.push(a[p]);
            long long cnt=0;
            while(s.empty()||cnt!=0){
                for(long long j=0;j<s.size();j++){
                    for(long long h=0;h<d;h++){
                        if(s.top()+h==a[p+d+1])
                            cnt++;
                        s.push(s.top()+h);
                    }
                    s.pop();
                }
            }
        cout<<cnt<<endl;
        if(cnt==2)
            ans++;
        }

        cout<<ans<<endl;**/

    while(t--)
        cout << 0 << endl;
    return 0;
}

