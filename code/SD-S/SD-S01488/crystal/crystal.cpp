#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
inline long long read(){
   long long s=0,w=1;char ch=getchar();
   while(!isdigit(ch)){if(ch=='-'){w=-1;}ch=getchar();}
   while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long n,m,ans,cnt,sum;
long long a[500010];
queue<int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<n;i++)a[i]=read();
	sort(a,a+n);
//	q.push(0);
	cnt=1;
	for(int i=1;i<n;i++){
		cnt++;
		sum+=(cnt-1)*(a[i]-a[i-1]);
//		printf("%lld ",sum);
		while(cnt>0&&sum>m){
			sum-=a[i]-a[i-cnt+1];
			cnt--;
		}
//		printf("%lld %lld\n",sum,cnt);
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
