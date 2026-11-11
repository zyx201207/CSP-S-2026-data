#include<bits/stdc++.h>
#define int long long
const int MAXN=5e5+10,mod=1e9+7;
using namespace std;
int n,m,maxn;
int a[MAXN],pre[MAXN],s;
int fn(int x){
    int l=1,mid,r=x,res=x;
    while(l<=r){
        mid=(l+r)/2;
        if(((x-mid)*a[x]-(pre[x-1]-pre[mid-1]))<=m){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return x-res+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        maxn=max(maxn,fn(i));
    }
    cout<<maxn;
    return 0;
}/*嗯，想进HN迷惑行为大赏，我这个行为确实很迷惑，正在想T2，还没写完呢*……*
太坏了这个yz，刚考完彩色片（csp，输入法打出来怎么是彩色片）就搞联考。
嗯以为考不好？T1用时30min挑战最长时长，T2竟然想到正解了，但是现在不想写（？。
没有时间写OI回忆录了，2h过去了T2还没写完，没有那么强去写很长的东西……。
就这样吧，miku&teto万岁^q^。
哦对了，洛谷uid1345325，快来关注！！
updata:不对，写前面几行的时候才只过了1h30min，现在是4：44，本区写完T2并测完大洋里了！
诶我的码力什么时候这么强了，竟然用40分钟不到就能写完T2代码吗。
今天状态真好啊……
不出意外我会有一等的对吧（此处应有礼炮）诶是不是应该也有7钩了。
哦明天是我的生日，如果真的有迷惑行为大赏的话那你们看到的时候我已经过完生日了嘻嘻
嗯，二等应该能拿到吧，我能进noip的对吧*/