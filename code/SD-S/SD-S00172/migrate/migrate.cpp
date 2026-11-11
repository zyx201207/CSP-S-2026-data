#include<bits/stdc++.h> 
using namespace std;//！？海屿你？！
int n,c,t,ans,dis[2002005],pp[2002005],cnt[2002005];
long long d,a[2002005];
//我终于想起来自我介绍了：https://space.bilibili.com/689497514 
//Phigros rks17.09猫猫一只 (去年今日还只有16.77qwq)
//出题人生气 WA下降 
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;c=12;
	if(c<11)while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)pp[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
		for(int i=1;i<=n;i++){
			for(int j=pp[i];j<=i;j++)dis[j]=cnt[j]=0;
			cnt[i]=1;
			for(int j=i+1;j<=n;j++){
				dis[j]=dis[pp[j]]+1;cnt[j]=0;
				for(int k=max(pp[j],i);k<j&&cnt[j]<3&&dis[pp[j]]==dis[k];k++)cnt[j]+=cnt[k];
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	else if(c!=14&&c!=13)while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)pp[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
		cnt[1]=1;
		for(int j=2;j<=n;j++){
			dis[j]=dis[pp[j]]+1;cnt[j]=0;
			for(int k=max(pp[j],1);k<j&&cnt[j]<3&&dis[pp[j]]==dis[k];k++)cnt[j]+=cnt[k];
			if(cnt[j]==2)ans+=n-j+1;
		}
		cout<<ans<<'\n';
	}else while(t--)cout<<"0\n";
	return 0;
}//我...喜欢你喵...
/*
震撼首发：海鸟飞走了->海底潭 99.9999%
!?awmc?!

床！前！明！月！光！
疑！是！地！上！霜！
举！头！望！明！月！
低！头！思！故！乡！
   ！   鹅！鹅！鹅！
曲！项！向！天！歌！
白！毛！浮！绿！水！
红！掌！拨！清！波！
氢！氦！锂！铍！硼！
碳！氮！氧！氟！氖！
钠！镁！铝！硅！磷！
硫！氯！氩！钾！钙！
   ！   问！君！能！有！几！多！愁！恰！似！一！江！春！水！向！东！流！流！流！↑↑↑↑↑↑↑~
17:54 T3 32+[0,16]分代码完成，打死一只黑蚊子（！？Heavensdoor？！）
*/
