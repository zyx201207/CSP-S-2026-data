//By JuRuoOIer
//Problem:migrate
//Expected:56 (1~10 n^2, 11~12 1, 13~14 n log n)
//idea:120min impl:26min
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<cctype>
#include<queue>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define LL __int128
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
ll c,T,n,d,a[2000010],dis[2000010],cnt[2000010];
queue<ll> q;
int main(){
	file();
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(d>=(a[1]-a[0])*2){
				cout<<max(n-d/(a[1]-a[0])*2+1,0ll);
			}
			else{
				cout<<0;
			}
			cout<<endl;
			continue;
		}
		if(c==13||c==14){
			ll ans=0;
			for(int i=0;i<n;i++){
				ll pos=upper_bound(a,a+n,a[i]+d)-1-a;
				if(pos-i>1){
					ll p2=upper_bound(a,a+n,a[pos-1]+d)-1-a;
					ll p3=upper_bound(a,a+n,a[pos-2]+d)-1-a;
					ans+=p2-p3;
				}
			}
			cout<<ans<<endl;
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				dis[j]=0;
				cnt[j]=0;
			}
			q.push(i);
			cnt[i]=1;
			while(q.size()){
				ll now=q.front();
				q.pop();
				ans+=(cnt[now]==2);
				for(int j=now-1;~j;j--){
					if(a[now]-a[j]>d){
						break;
					}
					if(!dis[j]){
						dis[j]=dis[now]+1;
						cnt[j]+=cnt[now];
						q.push(j);
					}
					else if(dis[j]==dis[now]+1){
						cnt[j]+=cnt[now];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
虽千万人逆我之 我仍执著
侠客行遍九州 恩仇奔波
刀光剑影里是谁的明眸璨璨如星火
纵使我双掌倚天 苍龙俘获
奈何降不住这 人心如魔
所谓天下第一 怎囿我天高海阔 
*/
