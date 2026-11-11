#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
struct node{
    int num;
    char ch;
}a[N];
ll ans;
//ll s;
int n;
inline int read(){
    int x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch==EOF) return 0;
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
        if(ch==EOF) break;
    }
    return x*f;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i].num=read();
        scanf("%c",&a[i].ch);
        //s+=a[i].num;
    }
    //printf("%lld",s);
    int i=1,j=n;
    while(i<j){
        if(a[i].num>a[j].num){
            a[i].num-=a[j].num;
            if(a[i].ch != a[j].ch) ans+=a[j].num;
            j--;
        }
        else if(a[i].num<a[j].num){
            a[j].num-=a[i].num;
            if(a[i].ch != a[j].ch) ans+=a[i].num;
            i++;
        }
        else{
            if(a[i].ch != a[j].ch) ans+=a[i].num;
            i++;j--;
        }
    }
    printf("%lld",ans);
    return 0;
}
