//8:52 速切t1 100+0+0+0=100pts
//freopen!!!
#include <bits/stdc++.h>
using namespace std;
int n;
//long long len=0;
long long a[200005];
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //11:01 我靠 差点乐极生悲了
    //让我想想
    //women ke yi zhijie cong liang duan bianli shu buxiangdeng de ge shu
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> s[i];
    }
    /*
    int mid=0;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=a[i];
        if(cnt>=len/2){
            mid=i;
            break;
        }
    }*/
    //hao xiang you dian xiang shuang zhi zhen
    int l=1,r=n;
    long long cnt=0,ans=0;
    bool f=1;
    while(l<r){
        if(cnt==0){
            if(a[l]<a[r])f=0;
            else f=1;
        }
        if(cnt+a[r]<a[l]&&f){
            cnt+=a[r];
            //隔壁那人能别吃东西了吗 我就带了罐口香糖
            if(s[l]!=s[r])ans+=a[r];
            r--;
        }
        else if(cnt+a[r]>a[l]&&f){
            if(s[l]!=s[r])ans+=(a[l]-cnt);
            a[r]-=(a[l]-cnt);
            l++;
            cnt=0;
        }
        else if(cnt+a[r]==a[l]&&f){
            if(s[l]!=s[r])ans+=a[r];
            cnt=0;
            l++;
            r--;
        }
        else if(cnt+a[l]<a[r]){
            cnt+=a[l];
            if(s[l]!=s[r])ans+=a[l];
            l++;
        }
        else if(cnt+a[l]>a[r]){
            if(s[l]!=s[r])ans+=(a[r]-cnt);
            a[l]-=(a[r]-cnt);
            r--;
            cnt=0;
        }
        else if(cnt+a[l]==a[r]){
            if(s[l]!=s[r])ans+=a[l];
            cnt=0;
            l++;
            r--;
        }
        //cout << l << ' ' << r << "   " << cnt << ' ' << ans << '\n';
    }
    cout << ans;
	return 0;
}
//输入法好难用
//看到这题有点怕 长的有点像dp 但是这个数据像诈骗题
//si lu wo yong pin yin xie le
//zhu yi dao ben ti shuju ji da  xian ran bu shi mo ni
// 8:59 感觉这题有点不好写 开T3去了
//9:11 回来了
//9:14 再看看t3？

//10:11 洋梨4没过 好烦
//我还有1=的风险吗

//10:22 没调过 好无力啊
//想吃北极甜虾
//或许我真的该afo了？毕竟我弱到s初赛都没过 而我已经初二了……
//唉
//luogu uid:1210305

//10：27 再调一调吧 到10：45还没调出来我就放弃

//10:35 越来越接近了
//10:40 ?洋梨5居然能过？
//先加个freopen 一会儿再看

//10:58 我去！！！！！！！！！！！！！！！！！！！！！！！！！！！！！我调出来了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！我去！！！！！！！！！！！！1111
//喂～～～～～俺个炊饼～～～～～～～马飞～～～～～～～～（
//啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
