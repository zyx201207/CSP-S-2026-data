#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct st{
    long long num;
    char f;
};
st a[N];
long long cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long k,l=1,r=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i].num>>a[i].f;
        r++;
    }
    while(l<r){
        if(a[l].f!=a[r].f){
            cnt+=min(a[l].num,a[r].num);
        }
        long long fr,se;
        fr=a[l].num;
        se=a[r].num;
        a[l].num-=min(fr,se);
        a[r].num-=min(fr,se);
        if(a[l].num==0) l++;
        if(a[r].num==0) r--;
    }
    cout<<cnt;
    return 0;
}

