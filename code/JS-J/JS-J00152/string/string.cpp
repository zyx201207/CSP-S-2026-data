#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,a[200010];
char c[200010];
int sum;

/*
                 (__) 
                 (oo) 
           /------\/ 
          / |    ||   
         *  /\---/\ 
            ~~   ~~   
..."Have you mooed today?"...
*/

struct headpos{
    int i,rank;//rank->the rank-th c[i] in a[i]
}head={1,1};

struct tailpos{
    int i,rank;//the last rank-th c[i] in a[i]
}tail;

bool operator<(const headpos& head,const tailpos& tail){
    if(head.i==tail.i&&(head.rank>=a[tail.i]-tail.rank+1))return false;
    return true;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    //head...tail
    tail={n,1};
    int ans=0;
    while (head.i<tail.i) {
            int curlen=min(a[head.i]-head.rank+1,a[tail.i]-tail.rank+1);
            if(c[head.i]!=c[tail.i])ans+=curlen;
            tail.rank+=curlen;
            head.rank+=curlen;
            if(tail.rank>a[tail.i]){
                tail.i--,tail.rank=1;
            }
            if(head.rank>a[head.i]){
                head.i++,head.rank=1;
            }
    }
    cout<<ans;
}