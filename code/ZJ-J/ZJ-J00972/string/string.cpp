#include<bits/stdc++.h>
#define int LL
#define LL long long
#define maxn 100005
using namespace std;
int n;
LL ans;
struct LXC{
	long long num;
	char c;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int find(LL x){
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)/2;
		if(a[mid-1].num<=x&&a[mid].num>=x) return mid;
		else if(a[mid].num<x) L=mid+1;
		else R=mid-1; 
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	a[1].num=0;
	for(int i=1;i<=n;i++){a[i].num=read(),a[i].c=read();a[i].num+=a[i-1].num;}
	int MID=find((a[n].num+1)/2);
	LL mi=(a[n].num+1)/2;
	LL right,left;
	if(a[n].num%2==1) right=a[MID].num-mi,left=mi-a[MID-1].num-1;
	else right=a[MID].num-mi-1,left=mi-a[MID-1].num-1;
	if(right>left){
//		if(a[MID-1].c!=a[MID].c) ans=ans+right-left;
	}
	else{
		if(a[MID+1].c!=a[MID].c) ans=ans+left-right;
	}
	for(int i=1;i<MID;i++){
		int nxt=find(a[n].num-a[i-1].num);
		LL cha=0;
		if(a[nxt].c!=a[i].c){
			cha=min(a[i].num-a[i-1].num,a[nxt].num-(a[n].num-a[i].num));
			ans+=cha;
		}
		int j=nxt+1;
		for(;j<=n&&a[j].num<a[n].num-a[i-1].num+1;j++){
			if(a[i].c!=a[j].c){
				ans+=a[j].num-a[j-1].num;
			}
		}
		if(a[j].num>a[n].num-a[i-1].num+1) continue;
		if(a[j].c!=a[i].c){
			ans=ans+(a[n].num-a[i-1].num-(a[j-1].num));
		}
	}
	printf("%lld\n",ans);
	return 0;
}