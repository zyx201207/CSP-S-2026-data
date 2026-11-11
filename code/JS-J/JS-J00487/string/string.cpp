#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nice{
    int num;
    char ch;
};
int n,pos1,pos2,t1;
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    vector<nice> a(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&(a[i].num),&(a[i].ch));
    }
    pos1=1;pos2=n;
    while(pos1<=pos2){
        if(a[pos1].num==a[pos2].num){
            if(a[pos1].ch!=a[pos2].ch){
                ans+=a[pos1].num;
            }
            pos1++;pos2--;
        }
        else if(a[pos1].num<a[pos2].num){
            if(a[pos1].ch!=a[pos2].ch){
                ans+=a[pos1].num;
            }
            a[pos2].num-=a[pos1].num;
            pos1++;
        }
        else if(a[pos1].num>a[pos2].num){
            if(a[pos1].ch!=a[pos2].ch){
                ans+=a[pos2].num;
            }
            a[pos1].num-=a[pos2].num;
            pos2--;
        }
    }
    printf("%lld",ans);
    return 0;
}
// I think it is two-pointer, 30 minutes, pass(local enviorment)