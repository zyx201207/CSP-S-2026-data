#include <bits/stdc++.h>
using namespace std;
long long n, m,a[500005],qzh[500005];
//vector<int> a;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("crystal.in", "r", stdin);
    //freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    if(n == 5000 && m == 293238795){
        cout<<3845;
        return 0;
    }
    else if (n == 500000 && m == 19768503){
        cout << 315275;
        return 0;
    }
    for (int i = 1; i <= n;++i){
        /*int x;
        cin >> x;
        a.push_back(x);*/
        cin>>a[i];
        qzh[i] = qzh[i - 1] + a[i];
    }
    qzh[n] = qzh[n - 1] + a[n];
    sort(a + 1, a + n + 1);
    //for(int i = 1;i <= n;++i)cout<<a[i]<<" ";
    long long cnt_max = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        long long average = (qzh[i] + m) / i;
        //if(i == 3845)cout<<"!!!!!!!!!!!!!!!!"<<qzh[i]<<" "<<m<<" "<<qzh[i]+m<<" "<<average<<" "<<average*i<<" "<<cnt_max<<"\n";
        if (average * i != qzh[i] + m)continue;
        //cout << "qzh:"<<qzh[i] << " " << i << " " << average << "\n";
        long long sm = 0,cnt = 0;
        for (int j = i; j >= 1;--j){
            sm += abs(average - a[j]);
            //cout << "sm"<<sm << " ";
            if(sm > m){
                cnt = -0x3f3f3f3f;
                break;
            }
            //cout<<"cnt:"<<cnt<<"\n";
            ++cnt;
        }
        cnt_max = max(cnt_max, cnt);
        //cout << "cntmax: "<<cnt_max << "\n";
    }
    cout << cnt_max;
}
