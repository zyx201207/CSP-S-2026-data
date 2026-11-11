//rp++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],c[N],ans=1,nw;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
    for(int i=1,j=1;i<=n;i++)
    {
        for(;j<=n;j++)
        {
            if(nw+c[j]*(j-i)>m){j--;break;}
            else nw+=c[j]*(j-i);
        }
        ans=max(ans,j-i+1);
        nw-=(a[j]-a[i-1]);
    }
    cout<<ans;
    return 0;
}
//CE shi shen me yi si???

/*
ni shi xin de kai tou shi de nei rong tong hua de jie wei
ni shi li suo dang ran de qi ji ni shi yue se zhen mei
ni shi sheng dan lao ren song gei wo hao hai zi de li wu
ni shi san qian mei li shi jie li wo de yi piao shui
suo yi rang wo zai kao jin yi dian dian yin wei ni tai wen nuan
wo hui zai bian de jian qiang yi dian dian yin wei ni tai rou ruan
jiao huan wu ming zhi jin se de qi yue gei bi ci sui yue
shuo hao cong jin yi hou yao qian zhe shou yin wei yao zou hen yuan

ni shi wo wan shui qian shan de mao xian yao zhao de biao ji dian
ni shi fen ge wo ren sheng de xian you jiang ta men xiang lian
ni shi qian shi qian ci de hui mou qian cheng qian de shou
ni shi qi yu suo you de yi qie shi wo de shi jie
suo yi qing ni zai shan liang yi dian dian jin guan wo tai ping fan
wo hui zai bian de rou ruan yi dian dian yin wei wo tai min gan
jiao huan wu ming zhi jin se de qi yue gei bi ci sui yue
shuo hao cong jin yi hou dou qian zhe shou bu guan yao zou duo yuan
*/
