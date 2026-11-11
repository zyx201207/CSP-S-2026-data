#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],s[500010],l,r,ans;
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    a[n+1]=2e18;
    for(ll i=1;i<=n+1;i++) s[i]=s[i-1]+a[i];
    l=1;//l表示最左边选了的，r表示最右边没选的
    for(ll i=1;i<=n;i++){
        while(a[i]*(i-l)-(s[i-1]-s[l-1])>m) l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
g++ -std=c++14 -O2 crystal.cpp -o crystal

首先考虑一个没有选在水晶上的位置
假设左边选了的水晶数量为l,右边选了的水晶数量为r
那么哪边多往哪边移动肯定不劣

所以最终可能的水晶数字肯定在一个已有的数字上

遍历所有可能的数字，然后二分次数再二分是两个log

考虑优化这个操作，尝试从上个形态转移过来？

每个形态实质上相当于选择左右的数字，每次扩大最近的那个

直到没有可扩的

好像可以从上一个转移、
毕竟左侧的优先级只会越来越少，右侧的优先级只会越来越大

具体怎么操作呢？
大概就是先左边向右移动到符合条件
然后再看如果左边距离大于右边就去掉一个左边
毕竟左右两边的数字大小是完全单调的
然后没有办法进行的时候应该就是最优情况了

???

hyw


读错题了！！

Only left!!!!


成功在T1浪费1h，惨淡收场！
*/