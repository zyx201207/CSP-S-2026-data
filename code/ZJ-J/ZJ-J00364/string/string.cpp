#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int l[N],r[N];
int ls[26],rs[26];
char s[N];
int n,ans=0,L,R,sl=0,sr=0;
void actl(){
	L--;
	int now=r[L]-l[L]+1;
//	printf("LLL%lld\n",now);
	for(int i=0;i<=25;i++){
		if(rs[i]!=0||sr==0){
			if(rs[i]>now){
				rs[i]-=now;
				sr-=now;
				if(i!=s[L])ans+=now;
		//		printf("-------------\n");
			}
			else {
				if(i!=s[L])ans+=rs[i];
				now-=rs[i];
			//	printf("%lld\n",now);
				rs[i]=0;
				sr=0;
				sl+=now;
				ls[s[L]]=now;
			}
		}
	}
}
void actr(){
	R++;
	int now=r[R]-l[R]+1;
	for(int i=0;i<=25;i++){
		if(ls[i]!=0||sl==0){
			if(ls[i]>now){
				ls[i]-=now;
				sl-=now;
				if(i!=s[R])ans+=now;
			}
			else {
				if(i!=s[R])ans+=ls[i];
				now-=ls[i];
				ls[i]=0;
				sl=0;
				sr+=now;
				rs[s[R]]=now;
			}
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	int sta=1;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		scanf("%lld %c",&x,&c);
		l[i]=sta;
		sta+=x;
		s[i]=c-'a';
		r[i]=sta-1;
	}
	sta--;
//	printf("%lld\n",sta);
	int x;
	int mid=sta/2+1;
	for(int i=1;i<=n;i++){
		if(mid<=r[i]&&mid>=l[i]){
			x=i;
			L=x,R=x;
			int lx,rx;
			if(sta%2==1){
				lx=max(mid-l[i],0ll);
				rx=max(r[i]-mid,0ll);
			}
			else {
				lx=max(mid-l[i],0ll);
				rx=max(r[i]-mid+1,0ll);
			}
			if(lx>rx){
				ls[s[i]]+=lx-rx;
				sl+=lx-rx;	
			}
			if(lx<rx){
				rs[s[i]]+=rx-lx;
				sr+=rx-lx;
			}
//			printf("%lld %lld\n",lx,rx);
			break;
		}
	}
//	printf("%lld %lld %lld %lld\n",sl,sr,L,R);
//	actl();
//	printf("----->%lld %lld %lld %lld\n",L,R,sl,sr);
//	actr();
//	printf("----->%lld %lld %lld %lld\n",L,R,sl,sr);
	while(!(L==1&&R==n)){
//		printf("----->%lld %lld %lld %lld\n",L,R,sl,sr);
		if(sl<sr){
			actl();
		}
		else if(sr<sl){
			actr();
		}
		else if(sr==sl){
			if(L==1)actr();
			else actl();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
