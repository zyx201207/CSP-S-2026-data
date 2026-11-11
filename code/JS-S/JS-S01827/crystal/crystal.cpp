#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long n,m,a[500005],cnt=1,ans=-0x3f3f3f3f;

deque<long long> q;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1);
    q.push_back(1);

    for (int i=2;i<=n;i++){
        long long cx = a[i]-a[q.back()];
        if (m>=cx*cnt){
            m-=cx*cnt;
            cnt++;
            q.push_back(i);
        }
        else{
            while (cnt>1 && m<cx*cnt){
                cnt--;
                m+=a[q.back()]-a[q.front()];
                q.pop_front();
            }
            if (cnt==1 && m<cx*cnt){
                q.pop_back();
                q.push_back(i);
            }
            else{
                m-=cx*cnt;
                cnt++;
                q.push_back(i);
            }
        }
        ans = max(cnt,ans);
    }


    cout << ans << endl;


    return 0;
}
