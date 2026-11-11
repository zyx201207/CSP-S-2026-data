#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,sum=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        sum+=b;
    }
    cout<<sum;
    return 0;
}//                                                                                            !
//yuan shen niu bi
//ai shang lei shen
//isolation 1234567
//wu bai nian lai,wo dou wang bu diao na ge yan shen,si zhi zhi zheng jiang xia bu si zu zhou de shi hou
//ta de yan zhong mei you bei min ye mei you kuai yi
//ming ming zhou wei dou shi qi qiu de ren me,si zhi zhi zheng yi jiu bu wei suo dong
//xian zai, ruo na wa,zheng shi wu!zheng shi ni de di ren!yu ren zhi yan!jie fang!ruo na wa!
