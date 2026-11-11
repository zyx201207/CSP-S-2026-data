#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int head=1,tail=n;
    while(head<=tail){
        if(head<tail){
            while(a[head]>=a[tail]&&head<tail){
                a[head]-=a[tail];
                if(c[head]!=c[tail]){
                    ans+=a[tail];

                }
                a[tail]=0;
                tail--;
            }
            while(a[head]<a[tail]&&head<tail){
                a[tail]-=a[head];
                if(c[head]!=c[tail]){
                    ans+=a[head];

                }
                a[head]=0;
                head++;
            }
        }
        if(head==tail){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}
