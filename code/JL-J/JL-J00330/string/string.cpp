#include<bits/stdc++.h>;
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct ayaka{
    ll l,r;
    char c;
};

ll a[N];
char c[N];
ayaka qj[N];
ll n;
ll sum=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        qj[i]={sum,sum+a[i]-1,c[i]}; // [l,r]
        sum+=a[i];
    }
    if(n<=1){
        cout<<0;
        return 0;
    }

    sum-=1;
    ll len=(sum+1)/2;
    ll ans = 0;
    int pos;
    deque<ayaka> q;
    for(int i=1;i<=n;i++){
        if(qj[i].r>len){
            if(qj[i].l<=len){
                if(sum%2==0){
                    q.push_back({qj[i].l,len,qj[i].c});
                    qj[i].l=len+1;
                    pos = i;
                }else{
                    if(qj[i].l<len) q.push_back({qj[i].l,len-1,qj[i].c});
                    qj[i].l=len+1;
                    pos = i;
                }
            }else{
                pos = i+1;
            }
            break;
        }else{
            if(sum%2==1&&qj[i].l==len){
                pos=i+1;
                break;
            }
            q.push_back({qj[i].l,qj[i].r,qj[i].c});
        }
    }

    for(int i=pos;i<=n;i++){
        while(!q.empty() && (sum-qj[i].r+1)<=q.back().l){
            if(qj[i].c!=q.back().c){
               ans += q.back().r - q.back().l + 1;
            }
            q.pop_back();
        }
        if(q.empty()) break;
        if(q.back().r >= (sum-qj[i].r+1)){
            if(qj[i].c!=q.back().c){
                ans+=q.back().r - (sum-qj[i].r);
            }
            q.back().r=sum-qj[i].r;
        }
    }
    cout<<ans;
    return 0;
}
