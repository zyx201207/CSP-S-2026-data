#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
signed n,a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(signed i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n,ans=0;
    while(i<=j){
        if(c[i]==c[j]){
            if(a[i]==a[j])
                a[i]=0,a[j]=0,i++,j--;
            else{
                if(a[i]>a[j])a[i]-=a[j],a[j]=0,j--;
                else a[j]-=a[i],a[i]=0,i++;
            }
        }
        else{
            if(a[i]==a[j])
                ans+=a[i],a[i]=0,a[j]=0,i++,j--;
            else{
                if(a[i]>a[j])ans+=a[j],a[i]-=a[j],a[j]=0,j--;
                else ans+=a[i],a[j]-=a[i],a[i]=0,i++;
            }
        }
        // for(int i=1;i<=n;i++)cout<<a[i]<<' ';
        // cout<<i<<' '<<j<<' '<<ans<<'\n';
    }
    cout<<ans;
}


// wo qu T1 zhe me jian dan, zhe cai shi
// wo zhe zhong lao sha zi xuan shou gai 
// xie de lao sha zi ti mu, zhi jie tong
// guo.
// wo qu wo zen me lang fei le 20 fen
// zhong zai T1 shang mian, gan jin
// kan T2.
// wo qu T2 chu zhe me nan, kan dou kan 
// bu dong, zhe dui yu wo lai shuo wu yi 
// shi yi ge tiao zhan.
// bu guo mei you guan xi, zhi jie tong 
// guo yang li.
// wo qu wo zen me be da yang li 4 ka le 
// qi si wo le zhe bu de bu rang wo jian
// cha dai ma.
// hen hao hao shi 10 min, wo yu guo le
// suo you da yang li, dan shi yi jing 
// kai shi 1 h le,wo bu jin huai yi wo 
// shi fou ke yi AK, dan wo shi lai can
// jia S zu de,ying gai mei guan xi.
// kan T3.