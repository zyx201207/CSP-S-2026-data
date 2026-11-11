#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3fll;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else if(x<10){
		putchar(x^48);
	}
	else{
		print(x/10);
		putchar((x%10)^48);
	}
}
const int N=2e6+10;
int n,d;
int x[N],f[N];
struct ST{
	int dat,l,r,len;
	int minn,cnt;
	int tag,tagc;
}t[N<<2];
void push_up(int num){
	t[num].dat=t[num<<1].dat+t[num<<1|1].dat;
	t[num].minn=min(t[num<<1].minn,t[num<<1|1].minn);
	t[num].cnt=0;
	if(t[num].minn==t[num<<1].minn){
		t[num].cnt+=t[num<<1].cnt;
	}
	if(t[num].minn==t[num<<1|1].minn){
		t[num].cnt+=t[num<<1|1].cnt;
	}
}
void build(int num,int l,int r){
	t[num].l=l,t[num].r=r,t[num].len=r-l+1;
	t[num].dat=t[num].tag=t[num].tagc=t[num].minn=0;
	if(l==r){
		t[num].cnt=0;
		return;
	}
	int mid=l+r>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
	push_up(num);
}
void mktag(int num,pair<int,int>val){
	t[num].tag+=val.first;
	t[num].minn+=val.first;
	t[num].dat+=val.first*t[num].len;
	t[num].cnt+=val.second;
	t[num].tagc+=val.second;
}
void push_down(int num){
	mktag(num<<1,make_pair(t[num].tag,t[num].tagc));
	mktag(num<<1|1,make_pair(t[num].tag,t[num].tagc));
	t[num].tag=t[num].tagc=0;
}
void add(int num,int L,int R,pair<int,int>val){
	if(L>R)return;
	int l=t[num].l,r=t[num].r;
	if(L<=l&&r<=R){
		mktag(num,val);
		return;
	}
	push_down(num);
	int mid=l+r>>1;
	if(L<=mid)add(num<<1,L,R,val);
	if(mid<R)add(num<<1|1,L,R,val);
	push_up(num);
}
int querysum(int num,int L,int R){
	if(L>R)return 0;
	int l=t[num].l,r=t[num].r;
	if(L<=l&&r<=R){
		return t[num].dat;
	}
	push_down(num);
	int mid=l+r>>1,res=0;
	if(L<=mid)res+=querysum(num<<1,L,R);
	if(mid<R)res+=querysum(num<<1|1,L,R);
	return res;
}
pair<int,int> querymin(int num,int L,int R){
	if(L>R)return {0,0};
	int l=t[num].l,r=t[num].r;
	if(L<=l&&r<=R){
		return {t[num].minn,t[num].cnt};
	}
	push_down(num);
	int mid=l+r>>1;
	pair<int,int>res=make_pair(inf,0ll),temp;
	if(L<=mid){
		temp=querymin(num<<1,L,R);
		if(res.first>temp.first)res=temp;
		else if(res.first==temp.first)res.second+=temp.second;
	}
	if(mid<R){
		temp=querymin(num<<1|1,L,R);
		if(res.first>temp.first)res=temp;
		else if(res.first==temp.first)res.second+=temp.second;
	}
	return res;
	
}
int q[N],head,tail;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
//	c=read(),T=read();
	cin>>c>>T;
	if(c<=10){
		while(T--){
//			n=read(),d=read();
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				x[i]=read();
//				cin>>x[i];
			}
			int ans=0;
			for(int k=1;k<=2;k++){
				head=1,tail=0;
				build(1,k,n);
				q[++tail]=k;
				add(1,k,k,make_pair(0,1));
				for(int i=k+1;i<=n;i++){
	//				cout<<i<<'\n';
					int l=lower_bound(x+k,x+n+1,x[i]-d)-x;
	//				cout<<l<<'\n';
					if(head==tail+1){
						q[++tail]=1;
						add(1,i,i,make_pair(0,1));
					}
					else{
						pair<int,int>temp=querymin(1,l,i-1);
						temp.first++;
						if(temp.second<=2){
							if(temp.second==2){
	//							cout<<i<<'\n';
								ans++;
							}
							add(1,i,i,temp);
							if(head==tail+1){
								q[++tail]=i;
								continue;
							}
	//						cout<<q[tail]<<"adfasdfasdf\n";
							if(temp!=querymin(1,q[tail],q[tail])){
								q[++tail]=i;
							}
						}
						else if(temp.second>=3){
							do{
								add(1,q[head],i-1,make_pair(-temp.first,-temp.second));
								head++;
								temp=querymin(1,q[tail],q[tail]);
							}while((querymin(1,i,i)).second>=3&&head<=tail);
						}
					}
	//				for(int i=1;i<=n;i++){
	//					cout<<(querymin(1,i,i)).first<<' ';
	//				}
	//				cout<<'\n';
	//				for(int i=1;i<=n;i++){
	//					cout<<(querymin(1,i,i)).second<<' ';
	//				}
	//				cout<<'\n';
	//				puts("---------------------");
				}
				for(int i=1;i<=tail;i++){
					q[i]=0;
				}
	//			puts("==========================");
			}
			print(ans);
			puts("");
//			cout<<ans<<'\n';
		}
		return 0;
	}
	else if(c==11||c==12){
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
//			cout<<n<<' '<<d<<' '<<x[2]-x[1]<<'\n';
			if(n<=3||d<x[3]-x[1]){
				print(0);
				puts("");
				continue;
			}
			int temp=d/(x[2]-x[1]);
			temp=(temp<<1)-1;
			if(n<=temp){
				print(0);
				puts("");
				continue;
			}
			print(n-temp);
			puts("");
			
//			if(T==2||T==1){
//				cout<<n<<' '<<d<<'\n';
//				for(int i=1;i<=n;i++){
//					cout<<x[i]<<' ';
//				}
//				cout<<'\n';
//			}
		}
	}
	else{
		while(T--){
			n=read(),d=read();
			int minn=inf;
			for(int i=1;i<=n;i++){
				x[i]=read();
				if(i>1)minn=min(minn,x[i]-x[i-1]);
			}
			if(minn>d){
				print(0);
				cout<<'\n';
			}
//			if(d>=x[3]-x[1]&&d<x[4]-x[1]){
//				print(n-2);
//			}
//			else print(0);
//			cout<<'\n';
		}
		
	}
}
