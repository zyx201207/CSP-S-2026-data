#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
long long a[maxn];
long long n , m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);

    sort(a+1 , a+1+n);
    vector<pair<long long , int> > q;
    for(int i = 1 ; i <= n; i++){
        long long cha = a[n] - a[i];
        int flag = 0;
        for(int j = 0 ; j < q.size() ; j++)
            if(q[j].first == cha){
                flag = 1;
                q[j].second ++; break;
            }
        if(flag == 0) q.push_back(make_pair(cha , 1));
    }

    long long ans = 0;
    for(int i = q.size()-1 ; i > 0 ; i--){
        int tmp = m;
        long long tmpans = q[i].second;
        //cout << q[i].second << endl;
        for(int j = i-1 ; j > 0 && tmp > 0; j--){
            long long tmpnum = q[j].second;
            //cout << q[j].second << endl;
            int gap = q[j].first - q[i].first;
            //cout << j << ' ' << gap << endl;
            int flag = 0;
            while(tmpnum > 0){
                if(tmp > gap){
                    tmpans ++; tmp -= gap; tmpnum--;
                }else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        ans = max(ans, tmpans);

        //cout << i << ' ' << ans << endl;
    }
    printf("%lld",ans+1);

    return 0;
}


