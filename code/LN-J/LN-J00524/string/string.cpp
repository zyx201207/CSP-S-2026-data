#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,pos;
pair<int,char> a[N];
long long ans,cnt,p,sum,cnt2;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i].first>>a[i].second;
        cnt+=a[i].first;
    }
    p = cnt/2;
    for(int i = 1;i <= n;i++){
        cnt2+=a[i].first;
        if(cnt2 > p){
            pos = i;
            break;
        }
    }
    int p1 = 1,p2 = n;
    while(p1 < pos&&p2 >= pos){
        if(a[p1].second==a[p2].second){
            if(a[p1].first <= a[p2].first){
                a[p2].first-=a[p1].first;
                p1++;
            }else{
                a[p1].first-=a[p2].first;
                p2--;
            }
        }else{
            if(a[p1].first <= a[p2].first){
                ans+=a[p1].first;
                a[p2].first-=a[p1].first;
                p1++;
            }else{
                ans+=a[p2].first;
                a[p1].first-=a[p2].first;
                p2--;
            }
        }
    }
    cout<<ans;
    return 0;
}
