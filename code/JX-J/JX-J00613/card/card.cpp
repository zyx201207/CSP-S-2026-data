#include<bits/stdc++.h>
using namespace std;
int sum[500005],n,ans[500005],a[500005],tot,lazy[500005],m,tree[2000020];
struct f{
    int w,z;
}s[500005];
bool cmp(f a1,f a2){
    if(a1.z!=a2.z) return a1.z<a2.z;
    return a1.w<a2.w;
}
void down(int p){
    tree[p]=max(lazy[p],tree[p]);
    lazy[p*2]=max(lazy[p],lazy[p*2]);
    lazy[p*2+1]=max(lazy[p],lazy[p*2+1]);
    lazy[p]=0;
}
void tree_add(int p,int l,int r,int ll,int rr,int su){
    tree[p]=max(tree[p],su);
    if(l==r) return ;
  //  if(l>=ll&&r<=rr){
   //     lazy[p]=max(lazy[p],su);
   //     return ;
  //  }
  //  down(p);
    int ld=p*2,rd=p*2+1,mid=(l+r)/2;
    if(ll<=mid) tree_add(ld,l,mid,ll,rr,su);
    if(rr>mid) tree_add(rd,mid+1,r,ll,rr,su);
}
int tree_cha(int p,int l,int r,int su){
    if(l==su&&r==su) return tree[p];
    down(p);
    int ld=p*2,rd=p*2+1,mid=(l+r)/2;
    if(su<=mid) return tree_cha(ld,l,mid,su);
    return tree_cha(rd,mid+1,r,su);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i].w=i;
        s[i].z=a[i];
	}
	sort(s+1,s+n+1,cmp);
	for(int i=2;i<=n;i++){
        if(s[i].z==s[i-1].z){
            tree_add(1,1,n,s[i-1].w+1,s[i].w,s[i-1].w);
        }
	}
	for(int i=1;i<=n;i++){
        ans[a[i]]+=i-tree_cha(1,1,n,i);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
