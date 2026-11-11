#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
int n,d;
const int N = 2e6+5;
int mini[N+5],num[N+5];
int x[N+5];
constexpr int inf =0x3f3f3f3f3f3f3f3f;
void Main(){
    cin>>n>>d;
    // cout<<n<<d<< " ";
    for (int i=1;i<=n;i++){
        cin>>x[i];
    }
    int ans=0;
    for (int s=1;s<=n;s++){
        vector<int> num(n+5),mini(n+5,inf);
        num[s]=1;mini[s]=0;
        for (int i=s+1;i<=n;i++){
            for(int j=s;j<i;j++){
                if (x[i]-x[j]<=d){
                    if (mini[i]>mini[j]+1){
                        num[i]=num[j];
                        mini[i]=mini[j]+1;
                    }
                    else if (mini[i]==mini[j]+1){
                        num[i]+=num[j];
                    }
                }
            }
            if (num[i]==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
void solve2(){
    // cin>>n>>d;
    // // cout<<n<<d<< " ";
    // for (int i=1;i<=n;i++){
    //     cin>>x[i];
    // }
    // int j=1;
    // for (int i=1;i<=n;i++){
    //     while (x[j]-x[i]<=d){
    //         j++;
    //     }
    //     if (upper_bound(x+1,x+n+1,x[i]+d)-lower_bound(x+1,x+n+1,))
    // }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    for (int i=1;i<=t;i++){
        if (c<=10)Main();
        else if (c==13||c==14){
            solve2();
        }
    }
    return 0;
}/*0 2 5 3 -2 -1 0 1 2 
6 2 -4 -3 -2 -1 3 6
*/
//gan jue hui shi zhao chu shuang jing dao yu dui de he xing na linag ge dao yu
//ran hou zai zuo you tuo zhuan  