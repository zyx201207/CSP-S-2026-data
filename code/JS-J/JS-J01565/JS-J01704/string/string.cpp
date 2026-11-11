#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=2e5+10;
struct node{
    int cnt;char ch;
}a[N];
int sum;
int l,L;
int r,R;
int n;
int ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int A; char ch;
        cin>>A>>ch;
        a[i].cnt=A,a[i].ch=ch;
        sum+=A;
    }
    l=1,r=n,L=1,R=sum;
    while(L<=R){
        if(a[l].ch!=a[r].ch) {
            if(a[l].cnt>a[r].cnt){
                ans+=a[r].cnt;
                //cerr<<r<<' '<<a[r].cnt<<endl;
            }else{
                ans+=a[l].cnt;
                //cerr<<l<<' '<<a[l].cnt<<endl;
            }
        }
        //cerr<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
        //int K;
        //cin>>K;
        if(a[l].cnt>a[r].cnt){
            a[l].cnt-=a[r].cnt;
            L+=a[r].cnt,R-=a[r].cnt;
            r--;
        }else if(a[l].cnt==a[r].cnt){
            L+=a[l].cnt,R-=a[l].cnt;
            l++,r--;
        }else{
            a[r].cnt-=a[l].cnt;
            L+=a[l].cnt,R-=a[l].cnt;
            l++;
        }
    }
    w(ans);
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
