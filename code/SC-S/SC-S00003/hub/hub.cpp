#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,du[2000005],maxx;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			int u,v;
			cin>>u>>v;
			du[u]++,du[v]++;
		}
		for(int i=1;i<=n;++i){
			maxx=max(maxx,du[i]);
		}
		if(k==2){
			cout<<"1\n";
		}else{
			cout<<"2\n";
		}
	}
	return 0;
}
/*
最后20分钟开始写的
这英改师我的最后一舞，因为明年就要高考了
希望有大佬会做sc迷惑行为大赏
诈骗一下
//freopen("hub.in","r",stdin);
//freopen("hub.out","w",stdout);
awa
luogu:zhz_cptbtptp
寄了XP
Miku Miku oo ee oo
Hallo
Am I working right today
I wonna watch the sunrise
I wonna be a part of something
Can you feel me in here
妄想感伤代偿联盟
不要相信T氏的话
爱言叶Ⅰ~Ⅴ
兔子洞
神的随波逐流
呐呐呐
好
歌姬失格
千本樱
时间不够了，就到这里了......
homo1145141919810
*/