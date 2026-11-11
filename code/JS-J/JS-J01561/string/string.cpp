#include <bits/stdc++.h>
using namespace std;
struct node{
    long long num;
    char c;
};
node p[200010],fp[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,k=0;
    long long l=0;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> p[++k].num >> p[k].c;
        l+=p[k].num;
        if(p[k].c==p[k-1].c){
            p[k-1].num+=p[k].num;
            k--;
        }
    }
    for(int i = 1;i<=k;i++){
        fp[i]=p[k-i+1];
    }
    int m=1,fm=1;
    long long ans=0,o=0;
    while(o<l/2){
        if(fp[fm].num<p[m].num){
            if(fp[fm].c!=p[m].c)
                ans+=fp[fm].num;
            o+=fp[fm].num;
            p[m].num-=fp[fm].num;
            fm++;
        }
        else if(fp[fm].num==p[m].num){
            if(fp[fm].c!=p[m].c)
                ans+=fp[fm].num;
            o+=fp[fm].num;
            fm++;
            m++;
        }
        else{
            if(fp[fm].c!=p[m].c)
                ans+=p[m].num;
            o+=p[m].num;
            fp[fm].num-=p[m].num;
            m++;
        }
    }

    cout << ans << endl;
    return 0;
}
