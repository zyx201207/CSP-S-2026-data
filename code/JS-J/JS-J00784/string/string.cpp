#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
unsigned long long ans;
long long a[N];
char c[N];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n == 1){
        cout<<0;
        return 0;
    }
    for(int i = 1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i = 2;i<=n;i++){
        if(c[i]!=c[i-1]) break;
        if(i == n){
            cout<<0;
            return 0;
        }
    }
    int head = 1,tail = n;
    while(head<tail){
        if(c[head] == c[tail]){
            a[head]-=min(a[head],a[tail]);
            a[tail]-=min(a[head],a[tail]);
            if(a[head]>a[tail]) tail--;
            else if(a[head]<a[tail]) head++;
            else {
                head++;
                tail--;
            }
        }else{
            ans+=min(a[head],a[tail]);
            a[head]-=min(a[head],a[tail]);
            a[tail]-=min(a[head],a[tail]);
            if(a[head]>a[tail]) tail--;
            else if(a[head]<a[tail]) head++;
            else {
                tail--;
                head++;
            }
        }
    }
    cout<<ans;
    return 0;
}
