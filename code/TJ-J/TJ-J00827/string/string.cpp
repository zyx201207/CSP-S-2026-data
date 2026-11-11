#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int cnt;
int ans;
//string s;
struct node{
	int num;
	char c;
}a[200003],b[200003],all[200003];
int pre[200003];
int anu,bnu;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
//	s="1";
	for(int i=1;i<=n;i++){
		int num;char c;
		cin>>num>>c;
		pre[i]=pre[i-1]+num;
		cnt+=num;
		all[i].c=c;all[i].num=num;
//		for(int j=1;j<=num;j++) s+=c;
	}
	int mid=(cnt+1)/2;
	for(int i=1;i<=n;i++){
		if(pre[i-1]<mid) {
			a[++anu].c=all[i].c;
			a[anu].num=min(mid,pre[i])-pre[i-1];
			if((cnt%2!=0)&&(pre[i]>=mid)&&(pre[i-1]<mid)) a[anu].num--;
		}
		if(pre[i]>mid){
			b[++bnu].c=all[i].c;
			b[bnu].num=pre[i]-max(mid,pre[i-1]);
		}
	}
	for(int i=1,j=bnu;i<=anu;i++){
		int val=a[i].num;
		char c=a[i].c;
		while(b[j].num<=val){
			if(b[j].c!=c) ans+=b[j].num;
			val-=b[j].num;
			j--;
		}
		if(b[j].c!=c) ans+=val;
		b[j].num-=val;
	}
//	cout<<s<<'\n';
//	for(int i=1;i<=cnt/2;i++){
//		if(s[i]!=s[cnt-i+1]) ans++;
//	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
