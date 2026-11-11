#include<bits/stdc++.h>
using std::pair;
using std::make_pair;
int n ;
pair<int,char> s[200200] ;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a ;
        char c[5] ;
        scanf("%d%s",&a,c+1);
        s[i]=make_pair(a,c[1]);
    }
    int posl=1,posr=n;
    long long ans=0LL;
    while(posl<posr){
        if(s[posl].first<=s[posr].first){
            if(s[posl].second!=s[posr].second) ans+=1LL*s[posl].first;
            s[posr].first-=s[posl].first;
            posl++;
            if(s[posr].first==0) posr--;
        }
        else{
            if(s[posl].second!=s[posr].second) ans+=1LL*s[posr].first;
            s[posl].first-=s[posr].first;
            posr--;
        }
    }
    printf("%lld",ans);
    return 0;
}
