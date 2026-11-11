#include<bits/stdc++.h>
//能量水晶
using namespace std;
long long c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,m;
    cin>>n>>m;
    for(long long i = 0;i < n;++i){
        cin>>c[i];
    }
    sort(c,c + n);
    long long ans = 0;
    //yi i hao shuijing wei zhong xin ji suan zui duo you duo shao ge shuijing keyi biancheng ta
    for(long long i = 1;i < n;++i){
        long long point = 0,ansa = 0,cnt = 0;
        long long centre = c[i];
        cnt = i - 1;
        while(point < m && cnt >= 0){
            point += centre - c[cnt] ;
            ansa++;
            cnt--;
            if(point > m){
                ansa--;
            }
        //cout<<i<<' '<<"this is ansa"<<ansa<<'\n'<<"this is ans"<<ans<<'\n';
        }
        ans = max(ans,ansa);
    }
    long long one = 1;
    cout<<ans + one;
    return 0;
}
