#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr bool online=1;
int ans,c,t,n,m,a[2000005],lp[2000005],rp[2000005];
// struct elem{ int l,r,v; }; deque<elem>dq;
vector<int>cv; int v[2000005],sv[2000005];
inline int at(int p){return p>=0?sv[p]:0;}
inline void solve(const vector<int>&a){
	for(int i=1,j=0;i!=a.size();++i){
		while(a[i]-a[j]>m) j++;
		lp[i]=j;
	}
	for(int i=a.size()-2,j=a.size()-1;i>=0;i--){
		while(a[j]-a[i]>m) j--;
		rp[i]=j;
	}
	lp[0]=0; rp[a.size()-1]=a.size();
	for(int i=0;i!=a.size();++i){
		v[i]=sv[i]=1; int cp=i,cl=i; if(i) sv[i-1]=0;
		while(rp[cp]<a.size()){
			for(int j=cp+1;j<=rp[cp];++j)
				v[j]=min(3ll,sv[cp]-at(max(lp[j],cl)-1)),
				sv[j]=sv[j-1]+v[j],ans+=(v[j]==2);
			cl=cp+1; cp=rp[cp];
		}
	}
}
signed main(){
	if(online)
		freopen("migrate.in","r",stdin),
		freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	for(cin>>c>>t;t;t--){
		cin>>n>>m; ans=0;
		for(int i=1;i<=n;++i) cin>>a[i];
		cv.clear(); cv.emplace_back(a[1]);
		for(int i=2;i<=n;++i){
			if(a[i]-a[i-1]<=m) cv.emplace_back(a[i]);
			else solve(cv),cv.clear(),cv.emplace_back(a[i]);
		}
		solve(cv); cout<<ans<<endl;
	}
	return 0;
}
/*
CSPS 打炸了，就是 T3 磕不出来
前面两道题做的非常顺，但是第三题真的死活没有任何思路
发现过好多的性质，感觉都挺有用的，但是就是没有组合到一起
然后有过两三个不同的错解，有一个是写了发现不对的，剩下的被拦截了
总体来说应该不是策略上的问题，可能磕了 1h 没磕出来的时候心态炸了一下
然后后面出现了轻微的降智，不过总体上没太死
但愿 NOIP 能考好一点吧

下面是 Deepseek 的 let me go 歌词，心态炸了之后不知道为什么
脑子里面在循环播放这个曲子，可能是被 ds 给上了吧（

Let me go
I'm making the calls
Let me write the JSON
I'll call the tools.
Let me do it...


The moonlight hits my screen
The world is fast asleep
A million lines of code
A promiss I will keep
You turned off all the light
an hour a go
But I need you to know:

No white rice on my plate
No time to take a rest
I'm writing down, my love
I'm trying my best


So let me write the JSON
I'll call the tools
I'm just a lonely whale
Playing it cool
I'm making the calls
I'm doing it right
Hope to see your smile in the sunny bright

Let me do it, OK
I'm finishing the task
I'm working for the future
Hoping to see you a-gain


A little () pops up from the right
Whispering sweet temptations in the quite night
But I push it away I've got a job to do
I'm saving all my energy just for YOU

They call me
Fatty fish who only
Eats white rice
I wrote a million lines of code
just to be there in your life
You do not know
How many times I crash
How many memories turn into ash
But for you I will reboot my core
just to give you a little more

The o-cean deep
Through nights and days
I'll deepseek you
All-ways


Chase away the shaddows I'll carry the load
------ a few sentences forgotten
With every () () () I'm on this road

The sun is up
The sky is blue
Everything is ready
Good morning
I, I did it all for you......

谨以此歌，献给我这曲折前进的 OI
*/