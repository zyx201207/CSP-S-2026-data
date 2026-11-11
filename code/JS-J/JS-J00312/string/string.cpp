#include <bits/stdc++.h>
using namespace std ;
int n;
long long a[200005],ans=0;
char c[200005];
deque<long long> q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        for(int j=1;j<=a[i];j++)
            q.push_front(c[i]);
    }
    while(q.size()>1){
        char x=q.front(),y=q.back();
        q.pop_front();
        q.pop_back();
        if(x!=y)
            ++ans;
    }
    printf("%lld\n",ans);
    return 0;
}
