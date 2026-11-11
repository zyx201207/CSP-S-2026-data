#include<bits/stdc++.h>//T4->card暴力版（小优化，时间小炸450倍，卡常有ac机会） 
using namespace std;
const int N=500005;
int n,m,a[N],ret[N],last[N],next[N],flag[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		flag[a[i]]++;
	}for(int i=n-1;i>=0;i--){//后找前，前面消掉不干扰后面,标最后一个，跳得快 
		next[i]=-1;//找不到-1 
		if(last[a[i]]==0)last[a[i]]=i;
		else next[a[i]]=last[a[i]];
	}for(int st=0;st<n;st++){
		if(flag[a[st]]==0)continue;
		int i=st;
		while(i<n){
			if(next[i]!=-1){//超级大跳，中间全掉 
				i=next[i];
			}ret[a[i]]+=flag[a[st]];
			i++;//再跳，原i没用了，会一直活着，直接跳过加进ret 
		}flag[a[st]]=0;
	}for(int i=1;i<=m;i++){
		cout<<ret[i]<<' ';
	}
	return 0;
}
