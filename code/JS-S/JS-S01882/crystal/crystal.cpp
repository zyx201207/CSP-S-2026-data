#include<bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(a) (int)(a.size())
#define pb push_back
#define mk make_pair
const int N=5e5+5;
struct node{
    int num,sum;
}b[N];
int cnt;
int n,m,a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int nownum=a[1],nowsum=1;
    for(int i=2;i<=n;i++){
        if(a[i]==nownum)nowsum++;
        else{
            b[++cnt].num=nownum;
            b[cnt].sum=nowsum;
            nownum=a[i];
            nowsum=1;
        }
    }
    b[++cnt].num=nownum;
    b[cnt].sum=nowsum;
    int maxn=b[1].sum,lascos=0,lsum=b[1].sum;
    int totsum=b[1].sum;
    for(int l=1,r=2;r<=cnt;r++){
        if(lascos+totsum*(b[r].num-b[r-1].num)<=m){
            lascos+=totsum*(b[r].num-b[r-1].num);
            totsum+=b[r].sum;
            maxn=max(maxn,totsum);

             continue;
        }
        else{
            int ned=(lascos+totsum*(b[r].num-b[r-1].num))-m;
            totsum+=b[r].sum;
            while(lsum*(b[r].num-b[l].num)<ned){
                ned-=lsum*(b[r].num-b[l].num);
                totsum-=lsum;
                l++;
                lsum=b[l].sum;
            }
             if(ned>0){
                if(l==r){
                    lascos=0;
                    lsum=b[r].sum;
                    totsum=lsum;
                    continue;
                }
                int gs=ned/(b[r].num-b[l].num);
                if(ned%(b[r].num-b[l].num))gs++;
                lsum-=gs;
                totsum-=gs;
                ned-=gs*(b[r].num-b[l].num);
                if(lsum==0){
                    l++;
                    lsum=b[l].sum;
                }
            }
            lascos=m-abs(ned);
            maxn=max(maxn,totsum);
        }
    }
    cout<<maxn;
    return 0;
}