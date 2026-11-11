#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    char c;
    int a1,l,r;
};
node a[200005];
int n,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a1>>a[i].c;
        a[i].l=a[i-1].r+1;
        a[i].r=a[i].l+a[i].a1-1;
    }
    int now1=1,now2=n,num1=a[1].r-a[1].l+1,num2=a[n].r-a[n].l+1,t;
    while(t<a[n].r/2){
        if(a[now1].c!=a[now2].c){
            if(num1<num2){
                ans+=num1;
                t+=num1;
                now1++;
                num2-=num1;
                num1=a[now1].r-a[now1].l+1;
            }
            else if(num1>num2){
                ans+=num2;
                t+=num2;
                now2--;
                num1-=num2;
                num2=a[now2].r-a[now2].l+1;
            }
            else{
                t+=num1;
                ans+=num1;
                now1++;
                now2--;
                num1=a[now1].r-a[now1].l+1;
                num2=a[now2].r-a[now2].l+1;
            }
        }
        else{
           if(num1<num2){
                t+=num1;
                now1++;
                num2-=num1;
                num1=a[now1].r-a[now1].l+1;
            }
            else if(num1>num2){
                t+=num2;
                now2--;
                num1-=num2;
                num2=a[now2].r-a[now2].l+1;
            }
            else{
                t+=num1;
                now1++;
                now2--;
                num1=a[now1].r-a[now1].l+1;
                num2=a[now2].r-a[now2].l+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*

*/
