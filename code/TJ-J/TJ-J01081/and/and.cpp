#include <cstdio>
#include <algorithm>

const int maxn=200005;

int a[maxn];
int n,m;

namespace force{
	bool ok(){return n<=2000&&m<=2000;}
	
	bool hasmem[2005][2005];
	int mem[2005][2005];
	int dfs(int now,int c){
		if(now>n) return c==m?2147483647:0;
		if(hasmem[now][c]) return mem[now][c];
		
		int ans=dfs(now+1,c);
		if(c<m) ans=std::max(ans,dfs(now+1,c+1)&a[now]);
		
		hasmem[now][c]=true,mem[now][c]=ans;
		return ans;
	}
	void solve(){
		printf("%d\n",dfs(1,0));
	}
}

namespace ans{
	struct SegmentTree{
		struct node{
			node *s[2];
			int l,r;
			int mid(){return (l+r)>>1;}
			
			int val;
			void update(){val=s[0]->val&s[1]->val;}
		}pool[maxn*2],*now,*root;
		
		node *newnode(int l,int r){
			node *p=now++;
			p->s[0]=nullptr,p->s[1]=nullptr;
			p->l=l,p->r=r;
			p->val=0;
			return p;
		}
		
		void build(node *p){
			if(p->l==p->r){
				p->val=a[p->l];
				return;
			}
			int mid=p->mid();
			p->s[0]=newnode(p->l,mid),p->s[1]=newnode(mid+1,p->r);
			build(p->s[0]),build(p->s[1]);
			p->update();
		}
		
		int query(node *p,int l,int r){
			if(l<=p->l&&p->r<=r) return p->val;
			
			int mid=p->mid(),ans=2147483647;
			if(l<=mid) ans&=query(p->s[0],l,r);
			if(mid<r)  ans&=query(p->s[1],l,r);
			return ans;
		}
		
		void init(int n){
			now=pool;
			root=newnode(1,n);
			build(root);
		}
		int query(int l,int r){
			return query(root,l,r);
		}
	}sgt;
	void solve(){
		std::sort(a+1,a+n+1);
		
		sgt.init(n);
		
		int ans=0;
		for(int i=1;i+m-1<=n;i++){
			ans=std::max(ans,sgt.query(i,i+m-1));
		}
		printf("%d\n",ans);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	
	if(force::ok()) force::solve();
	else ans::solve();
	return 0;
}
