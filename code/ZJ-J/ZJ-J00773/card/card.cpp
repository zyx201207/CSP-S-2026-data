#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
int n,m;
int a[500005];
long long la[300005];
long long cnt[300005];
long long tim[300005];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		la[a[i]]=i;
	}
	long long fs=0;
	for(int i=1;i<=n;i++){
//		cout<<fs<<" ";
		if(tim[a[i]]==0){
			
			cnt[a[i]]=max(cnt[a[i]],i-fs);
			if(i==la[a[i]])continue;
			tim[a[i]]=i-fs;
			fs+=(i-fs);
		}else{
			fs-=tim[a[i]];
			cnt[a[i]]=max(cnt[a[i]],i-fs);
			tim[a[i]]=i-fs;
			if(i!=la[a[i]])fs+=i-fs;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
I_don_t_want_to_AFO{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
/*
8:30
kai T1
zhe sha jian dan ti
dou wo ne
8:46
T1 AC
kai T2
???
zai bi T1 jian dan
tang
9:01
T2 AC
T3 shi sha
ei! zhe wo zuo guo lei si de
zhe bu tang ti ?
9:12
???
T3 AC
shui wan le
T4 shi sha
kan zhe hao nan
bu dui
rang wo shou wan yi xia
10:22 
zhe you dian xiao nan
ei?! zhe bu guo l
10:31
T4 AC
AK
you dian jian dan
zong ti ping jia
Trick||Treat!
qiu hu guan
luogu 910022
mi huo xing wei da shang yao xuan wo a
qq le
*/
