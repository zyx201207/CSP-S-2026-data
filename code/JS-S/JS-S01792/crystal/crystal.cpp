#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],cnt,mm,ans,aa[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++){
        cnt = 0;
        mm = m;
        for(int j = 1;j <= n;j++) aa[i] = a[i];
        for(int j = i - 1;j >= 1;j--)
            if(mm >= a[i] - a[j]){
                aa[j] = a[i];
                mm -= a[i] - a[j];
            }
        for(int j = 1;j <= n;j++)
            if(a[i] == aa[j]) cnt++;
        ans = max(ans,cnt);
    }
    cout<<ans;
    //bu hui :) :) hao xiang you fen :) :) :)
    return 0;
}
//dong yu yi shi,sang yu fei wan.--<teng wang ge xu>
//zhe yi lu feng yu jian cheng xiang qian fang,ye ceng zai deng huo lan shan chu chou chang.--<jing shi guang>(kuai qu ting!)
//shui xu ni qu tian shang ren jian,shui tong ni you hen hai qing tian.--<fu ke hui yi>(kuai qu ting!)
//kuai qu ting <guang liang><da meng gui><wo men bu san><wan li chang feng>
//jv zi hao hao chi!hao wu liao!yi ti dou bu hui!cheng gong gan fei liang tai dian nao!
//zhu kan dao zhe ju hua de ren huo 100000000000000000 sui!!!
