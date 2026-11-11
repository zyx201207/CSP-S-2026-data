// 华风夏韵，洛水天依！

/*
最暗淡的一个 梦最为炽热
万千孤单焰火 让这虚构灵魂鲜活！！！ 
至少在这一刻 热爱不问为何
存在为将心声响彻

\COP/\COP/\COP/


最后一次拥抱我吧 哪怕只有海风 
*/

#include<bits/stdc++.h>

#define int long long
//#define double long double
#define il inline
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define multitest 1

using namespace std;
bool mem_beg;

const int N=2e6+5,M=6e5+5,V=6e5+5,mod=998244353;
const int dx[10]={0,1,-1,0,0,1,1,-1,-1},dy[10]={0,0,0,1,-1,1,-1,1,-1};
const double eps=1e-9;

il void read(int &x){char c;bool o=0;while((c=getchar())<'0'||c>'9')c=='-'&&(o=1);x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);o&&(x=-x);}

int __T=1,test_id;

int n,d,a[N];

namespace sub1
{
	int far[N];
	vector <int> ch;
	
	il void Solve()
	{
		for(int l=1,r=1;l<=n;++l)
		{
			while(a[r]-a[l]<=d&&r<=n) ++r; --r;
			far[l]=r;
		}
		
//		cerr<<"far : "; rep(i,1,n) cerr<<far[i]<<" \n"[i==n];
		
		int ans=0,ed,ok,sz,okt;
		/*
		ch 已选择的落脚点 
		ed 下一个可达的最远位置 
		ok 可替换位置个数 
		sz ch 的 size 
		okt 临时ok 
		*/
		rep(l,1,n)
		{
			ed=far[l],ok=0,sz=1,okt=0;
			ch.clear(),ch.pb(l);
			
			rep(r,l,n)
			{
				if(r^l && a[r]-a[r-1]>d) break;
				okt=0;
				
				if(r==ed)
				{
					ch.pb(ed),++sz,ed=far[ed];
					if(sz<=2) ;
					else
					{
						if(far[ch[sz-2]-1]>=r)
						{
							++ok;
							if(ok>1) break;
							if(sz>3 && far[ch[sz-3]-1]>=ch[sz-2]-1) break; //++ok; 上上个也可以换 
							if(ch[sz-2]-2>0 && far[ch[sz-2]-2]>=r) break; //++ok; 上个可以往前移两位 
						}
					}
				} 
				
				else
				{
					if(sz==1) ;
					else
					{
						if(far[ch[sz-1]-1]>=r)
						{
							++okt;
							if(sz>2 && far[ch[sz-2]-1]>=ch[sz-1]-1) continue; //++okt; 上上个也可以换 
							if(ch[sz-1]-2>0 && far[ch[sz-1]-2]>=r) continue; //++okt; 上个可以往前移两位 
						}
					}
				}
				
				if(ok>1) break;
				(ok+okt==1)&&++ans;
//				cerr<<l<<' '<<r<<" | ans = "<<ans<<" | ed = "<<ed<<" , ok = "<<ok<<" , okt = "<<okt<<" , sz = "<<sz<<'\n';
			}
		}
		
		printf("%lld\n",ans);
		
		ch.clear();
		rep(i,0,n+1) far[i]=0;
	}
}

namespace subA
{
	il void Solve()
	{
		int ans=0,m=a[2]-a[1],s=d/m;
//		cerr<<"m = "<<m<<" , s = "<<s<<'\n';
		if(s<=1) ans=0;
		else ans=max(n-s*2+1,0ll);
//		rep(len,1,n-1)
//		{
//			if(len%s==0||s>=len) continue;
//			if(len/s==1&&len+1==s*2) ans+=n-len+1;
//		}
		printf("%lld\n",ans);
	}
}

namespace subB
{
	il void Solve()
	{
		
	}
}

il void Solve()
{
	read(n),read(d); rep(i,1,n) read(a[i]);
//	cerr<<"lol]"<<endl;
//	scanf("%lld%lld",&n,&d);n=10; rep(i,1,10) scanf("%lld",&a[i]);
//	cerr<<n<<' '<<d<<' '<<a[10]<<endl;
	
//	if(n<=10000) sub1::Solve();
//	return; 
	
	if(n<=2) printf("0\n");
	else if(test_id>= 1&&test_id<=10) sub1::Solve();
	else if(test_id>=11&&test_id<=12) subA::Solve();
	else if(test_id>=13&&test_id<=14) subB::Solve();
	else printf("0\n");
}

il void Init()
{
	read(test_id);
}

il void Clear()
{
	rep(i,0,n+2) a[i]=0;
	n=d=0;
}

bool mem_end;
signed main()
{
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"Memory = %.3lf MB\n\n",abs(&mem_beg-&mem_end)/1024./1024.);
	Init(),multitest&&(read(__T),1);
	rep(__Ti,1,__T) Solve(),__Ti!=__T&&(Clear(),1);
//	fprintf(stderr,"\nTime = %.3lf ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

/*
n<=5000 | 1~10 40pts | O(n^2) 换落脚点
性质 A | 11~12 8pts | O(n) 枚举长度，随便搞搞
? 性质 B | 13~14 8pts | O(n) 特殊位置左/右作为替换的落脚点 

17:37 终于调过去 48pts 了 
性质B有时间再写吧，先开D 
*/ 

/*
0 1
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936

---

1 1
5 3
-3 0 2 3 4

ans=2

*/
