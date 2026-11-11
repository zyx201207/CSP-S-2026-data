#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
vector<ll>a;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),cmp);
    ll ans=a[0];
    for(int i=1;i<m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
/*
小 R 有 n 个非负整数 a 1 , a 2 , . . . , a n 。
小 X 给了小 R 一个正整数 m,并要求小 R 从这 n 个非负整数中选出 恰
. 好
. m 个,
使得选出的 m 个数的 二
. 进
. 制
. 按
. 位
. 与的值最大。
.
你需要帮助小 R 求出,他能选出的 m 个数的按位与的最大值。
从文件 and.in 中读入数据。
输入的第一行包含两个正整数 n, m。
输入的第二行包含 n 个非负整数 a 1 , a 2 , . . . , a n ,依次表示小 R 的 n 个非负整数。
*/
