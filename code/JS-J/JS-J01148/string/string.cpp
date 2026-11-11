#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct number{
    long long num;
    char ch;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].num);
        scanf(" %c",&a[i].ch);
    }
    int head=1,tail=n;
    while(head<tail){
        if(a[head].ch==a[tail].ch){
            if(a[head].num>a[tail].num){
                a[head].num-=a[tail].num;
                tail--;
            }else if(a[head].num<a[tail].num){
                a[tail].num-=a[head].num;
                head++;
            }else if(a[head].num==a[tail].num){
                head++;
                tail--;
            }
        }else{
            if(a[head].num>a[tail].num){
                a[tail].ch=a[head].ch;
                ans+=a[tail].num;
            }else if(a[head].num<a[tail].num){
                a[head].ch=a[tail].ch;
                ans+=a[head].num;
            }else if(a[head].num==a[tail].num){
                ans+=a[head].num;
                head++;
                tail--;
            }
        }
    }
    printf("%lld",ans);
}
