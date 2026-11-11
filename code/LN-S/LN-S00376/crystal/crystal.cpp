#include <bits/stdc++.h>
using namespace std;
vector <long long> a;
int n;
long long m,u,mina = 1e12+7,minb = 1e12+7;
int cnt2 = -1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> u;
        mina = min(mina,u);
        a.push_back(u);
    }
    bool flag = false;
    while(!flag){
        int cnt = 0;
        int cnt1 = 0;
        for(int i = 0;i<a.size();i++){
            if(a[i]<mina){
                a[i] = mina;
            }
            if(a[i] == mina){
                cnt++;
                continue;
            }
            minb = min(a[i],minb);
        }
        long long cha = minb-mina;
        if(cha<=0){
            cnt2 = n;
            break;
        }
        for(int i = 1;i<=cnt;i++){
            if(m-cha>=0){
                cnt1++;
                m=m-cha;
            }else{
                flag = true;
                break;
            }
        }
        cnt2 = max(cnt,cnt2);
        mina = minb;
        minb = 1e12+7;
    }
    cout << cnt2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
