#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N];
struct node{
    int l,r,sum,add;
};
node tr[N<<2];
void push_up(int p){
    int ls = p<<1,rs = p<<1|1;
    tr[p].sum = tr[ls].sum+tr[rs].sum;
}
void push_down(int p){
    if(tr[p].add!=0){
        int tmp = tr[p].add;
        int ls = p<<1;
        int rs = p<<1|1;
        tr[ls].sum +=tmp*(tr[ls].r-tr[ls].l+1);
        tr[ls].add+=tmp;
        tr[rs].sum +=tmp*(tr[rs].r-tr[rs].l+1);
        tr[rs].add+=tmp;
        tr[p].add = 0;
    }
}
void build(int p,int L,int R){
    tr[p].l = L;
    tr[p].r= R;
    tr[p].sum = 0;
    tr[p].add = 0;
    if(L==R){
        tr[p].sum = a[L];
        return;
    }
    int mid = (L+R)>>1,ls = p<<1,rs = p<<1|1;
    build(ls,L,mid);
    build(rs,mid+1,R);
    push_up(p);
}
int query(int p,int L,int R){
    if(tr[p].l>=L&&tr[p].r<=R){
        return tr[p].sum;
    }
    push_down(p);
    int res = 0,mid = (tr[p].l+tr[p].r)>>1;
    int ls = p<<1;
    int rs = p<<1|1;
    if(L<=mid)res+=query(ls,L,R);
    if(R>mid)res+=query(rs,L,R);
    return res;
}
void update(int p,int L,int R,int k){
    if(tr[p].l>=L&&tr[p].r<=R){
        tr[p].sum+=k*(tr[p].r-tr[p].l+1);
        tr[p].add+=k;
        return ;
    }
    push_down(p);
    int mid = (tr[p].l+tr[p].r)>>1;
    int ls = p<<1;
    int rs = p<<1|1;
    if(L<=mid)update(ls,L,R,k);
    if(R>mid)update(rs,L,R,k);
    push_up(p);
}
int main (){
    freopen("hub","r",stdin);
    freopen("hub","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    build(1,1,n);
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int x,y,k;
            cin >> x >> y >> k;
            update(1,x,y,k);
        }else{
            int x,y;
            cin >> x >> y;
            cout << query(1,x,y) << '\n';
        }
    }
    return 0;
}
