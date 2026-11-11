#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
        while(t--){
        int n,m;
        int b[1000006]={0};
        memset(b,0,sizeof(b));
        cin>>n>>m;
        for(int i=0;i<n-1;i++){
            int c,d;
            cin>>c>>d;
            b[c]++;b[d]++;

        }
        bool f=1;
        for(int i=1;i<=n;i++){
            if(b[i]>=m){
                cout<<1<<endl;
                f=0;
                break;
            }
        }
        if(f) cout<<2<<endl;
        cout<<endl;
    }
    return 0;
}//                                                                                 76
//wu bai nian lai,wo dou wang bu diao na ge yan shen1,si zhi zhi zheng jiang xia bu si zu zhou de shi hou
//xian zai, ruo na wa,zheng shi wu!zheng shi ni de di ren!yu ren zhi yan!jie fang!ruo 9na wa
//huai min yi wei qin,xiang yu bu yu zhong ting
//ting xia ru ji shui kong ming,shou zhong zao,xing jiao heng gai zhu bai
