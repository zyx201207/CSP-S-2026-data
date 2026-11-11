#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,a[2000006],can_end[2000006],can_front[2000006];

long long ans;

deque<int> q;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
    while (t--){
        memset(can_end,0x3f,sizeof(can_end));
        memset(can_front,0x3f,sizeof(can_front));
        cin >> n >> d;
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        ans=0;
        q.push_back(1);

        for (int i=2;i<=n;i++){
            while (!q.empty() && a[i]-a[q.front()]>d){
                can_end[q.front()] = q.back();
                can_front[q.back()] = min(can_front[q.back()],q.front());
                q.pop_front();
            }
            q.push_back(i);
        }

        while (!q.empty()){
            can_end[q.front()] = n;
            can_front[n] = min(can_front[q.back()],q.front());
            q.pop_front();
        }




        for (int i=1;i<=n;i++){
            if (can_end[i]-i==3) ans++;

            int m=can_end[can_end[i]-1];

            for (int j=m;j>=can_end[i]+1;j--){
                if (can_front[j]==can_end[i]-1) ans++;
            }

        }

        cout << ans << endl;
    }
	return 0;
}
