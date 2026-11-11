#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const ll M=5e5+10;
const ll N=510;
ll w[M],k[N],f[N][N];
ll c,n,m,d,q;
struct lane{
	ll i,t;
};
vector<lane>sta[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)w[i]=read();
	for(ll i=1;i<=n;i++){
		k[i]=read();
		for(ll j=1;j<=k[i];j++){
			ll A,T;
			A=read(),T=read();
			lane tmp;
			tmp.i=i,tmp.t=T;
			sta[A].push_back(tmp);
		}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i==j)f[i][j]=0;
			else f[i][j]=1e18;
	for(ll i=1;i<=m;i++){
		ll len=sta[i].size();
		if(len<=1)continue;
		for(ll j=0;j<len;j++)
			for(ll k=0;k<len;k++){
				ll K=sta[i][k].i,J=sta[i][j].i;
				ll wk=sta[i][k].t,wj=sta[i][j].t;
				f[J][K]=f[K][J]=min(f[J][K],wk+wj);
			}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		ll ans=1e18;
		ll x,y;
		x=read(),y=read();
		ll lenx=sta[x].size(),leny=sta[y].size();
		for(ll i=0;i<lenx;i++){
			for(ll j=0;j<leny;j++){
				ll I=sta[x][i].i,J=sta[y][j].i;
				ll wi=sta[x][i].t,wj=sta[y][j].t;
				ans=min(ans,f[I][J]+wi+wj);
			}
		}
		write(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
/*
tag:114514 kkksc03 ccf feropen retrun luogu chenzhe
little composition
first time i write such a thing
inferring from my name
iv already learnt olympics in informatics
for 7 years
during the 7 long years
in terms of the commen sense i have wasted my life
no noip 1=
in the first 5years iv hardly learnt anything
when i was in the computer classroom
i played nothing but video games
so it is
but theres a saying in my mermory
it was a cold rainy night
i surfed through the profile of the ones i subscribed to
and read an enlarged quote
'many year afterwards
you sit and ponder over your oi life
unsuccessful u actually have been
when somebody ask whats the meaning of all these days and nights
do not regret it
as
'rao yuan de lu, zong you feng jing''
so what i wanna do now
is not regrets, crying
but to make it meaningful
thanks for everyone i know
thanks for all my friends
thanks for my oi teachers:teacher wang,teacher yuan and teacher ma
thanks for my parents
2026csps:100+100+?+?(cheng/huang lv/lan zi/hei hei)
(ps: iv never even touched c++ since noip2025 but how i can ac t2 now?
REDICULOS)
--harvey2019 luoguid:283541
an ordinary sh senior three student
if anyone wanto make friends with me
welcome to dm me for qq
>_<
*/
