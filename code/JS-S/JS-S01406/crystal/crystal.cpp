#include<bits/stdc++.h>
using namespace std;

queue<long long> q;
int ans;
int n;
int cur_pos;
long long m;
long long a[500005];
long long cur_num;


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);

    cur_num=a[0];
    cur_pos=1;
    q.push(a[0]);
    for(int i=1;i<n;i++){
        while(m<q.size()*(a[cur_pos]-cur_num)&&(!q.empty())){
            m+=cur_num-q.front();
            q.pop();
        }

        m-=q.size()*(a[cur_pos]-cur_num);

        q.push(a[cur_pos]);
        cur_num=a[cur_pos];
        cur_pos++;
        ans=max(ans,(int)q.size());
    }

    cout << ans;
    return 0;
}
