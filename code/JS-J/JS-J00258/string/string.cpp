#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct Edge{
    char op;
    long long num;
}e[200005];
int l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){

        scanf("%lld",&e[i].num);
        cin>>e[i].op;
    }
    l=1;
    r=n;
    while(l<=r){
        if(e[l].op==e[r].op){
            if(e[l].num==e[r].num){
                l++;
                r--;
            }
            else if(e[l].num<e[r].num){
                e[r].num-=e[l].num;
                l++;
            }
            else{
                e[l].num-=e[r].num;
                r--;
            }
        }
        else{
            if(e[l].num==e[r].num){
                ans+=e[l].num;
                l++;
                r--;
            }
            else if(e[l].num<e[r].num){
                ans+=e[l].num;
                e[r].num-=e[l].num;
                l++;
            }
            else{
                ans+=e[r].num;
                e[l].num-=e[r].num;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
