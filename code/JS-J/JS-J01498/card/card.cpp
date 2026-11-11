#include <bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,m,head,tail;
int a[N],pos,l[N],q[N],res[N];
bool flag[N];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(l[a[i]]==0)  l[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        head=tail=0;
        head=1;
        for(int j=1;j<=m;j++)   l[j]=0;
        /*for(int j=1;j<=n;j++) {
            q[++tail]=a[j];
            if(l[a[j]]==0)  l[a[j]]=tail;
        }*/
        for(int j=i;j<=n;j++) {
            if(l[a[j]]==0) {
                q[++tail]=a[j];
                l[a[j]]=tail;
                continue;
            }
            while(tail!=l[a[j]]) {
                if(l[q[tail]]==tail)    l[q[tail]]=0;
                if(tail<0)  break;;
                tail--;
            }
        }
        for(int j=head;j<=tail;j++) res[q[j]]++/*,cout<<q[j]<<" \n"[j==tail]*/;
    }
    for(int i=1;i<=m;i++)   cout<<res[i]<<" \n"[i==m];
    return 0;
}