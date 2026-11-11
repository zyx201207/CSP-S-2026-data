#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    char s;
    long long c;
}a[200005];
queue<node> l;
queue<node> r;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].c>>a[i].s;
    }
    int L=1,R=n;
    int flag=0;
    while(L<R){
        if(flag==0){
            int sum=a[L].c-a[R].c;
            if(sum==0){
                ans+= a[L].s!=a[R].s ? a[L].c : 0;
                L++;
                R--;
            }else{
                ans+= a[L].s!=a[R].s ? min(a[L].c,a[R].c) : 0;
                if(sum>0){
                    node x={a[L].s,sum};
                    l.push(x);
                    flag=1;
                    R--;
                }else{
                    node x={a[R].s,-sum};
                    r.push(x);
                    flag=-1;
                    L++;
                }
            }

        }else if(flag==1){
            node y=l.front();
            l.pop();
            int sum=y.c-a[R].c;
            if(sum==0){
                flag=0;
                ans+= y.s!=a[R].s ? y.c : 0;
                L++;
                R--;
            }else {
                ans+= y.s!=a[R].s ? min(y.c,a[R].c) : 0;
                if(sum>0){
                    node x={y.s,sum};
                    l.push(x);
                    flag=1;
                    R--;
                }else{
                    node x={a[R].s,-sum};
                    r.push(x);
                    flag=-1;
                    L++;
                }
            }
        }else{
            node y=r.front();
            r.pop();
            int sum=a[L].c-y.c;
            if(sum==0){
                flag=0;
                ans+= a[L].s!=y.s ? y.c : 0;
                L++;
                R--;
            }else{
                ans+= a[L].s!=y.s ? min(a[L].c,y.c) : 0;
                if(sum>0){
                    node x={a[L].s,sum};
                    l.push(x);
                    flag=1;
                    R--;
                }else{
                    node x={y.s,-sum};
                    r.push(x);
                    flag=-1;
                    L++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
