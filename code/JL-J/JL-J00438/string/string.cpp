#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
struct node{
    int cnt;
    char c;
}a[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].cnt>>a[i].c;
    int l=1,r=n;
    while(l<=r){
        if(a[l].c==a[r].c){
            if(a[l].cnt==a[r].cnt)l++,r--;
            else if(a[l].cnt>a[r].cnt){
                a[l].cnt-=a[r].cnt;
                r--;
            }
            else{
                a[r].cnt-=a[l].cnt;
                l++;
            }
        }
        else{
            if(a[l].cnt==a[r].cnt){
                ans+=a[l].cnt;
                l++,r--;
            }
            else if(a[l].cnt>a[r].cnt){
                ans+=a[r].cnt;
                a[l].cnt-=a[r].cnt;
                r--;
            }
            else{
                ans+=a[l].cnt;
                a[r].cnt-=a[l].cnt;
                l++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
