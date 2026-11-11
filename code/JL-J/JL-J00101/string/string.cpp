#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c;
    c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return f*r;
}
struct node{
    int num;
    char c;
}a[200005];
int n,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    int num1=0,num2=0,sum=0;
    for(int i=1;i<=n;i++){
        a[i].num=read();
        a[i].c=getchar();
        getchar();
        num2+=a[i].num;
        sum+=a[i].num;
    }
    for(int l=1,r=n+1;l<r;l++){
        num1+=a[l].num;
        if(a[l].c!=a[r].c){
            if(sum-num2+1<=num1){
                ans+=(sum-num2)-(num1-a[l].num);
            }
            else{
                ans+=a[l].num;
            }
        }
        while(num1>=sum-num2){
            r--;
            num2-=a[r].num;
            if(a[l].c!=a[r].c){
                if(sum-num2+1>num1){
                    ans+=(num2+a[r].num)-(sum-num1);
                }
                else{
                    ans+=a[r].num;
                }
            }
        }
        //cout<<num1<<' '<<num2<<' '<<ans<<' '<<l<<' '<<r<<endl;
    }
    cout<<ans;
    return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
