#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N],n,sl,k[N],kkk;
char c[N],s[10000001];
long long l=0,ans,ed,len,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);//cout<<n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		k[i]=a[i];
		len+=a[i];
	}kkk=len&1;
	if(len<=10000000){
		for(int i=1;i<=n;i++){
		while(a[i]){
		s[++cnt]=c[i];
		a[i]--;	
		}
		}
		for(int i=1;i<=cnt/2+kkk;i++){
		if(s[i]!=s[cnt-i+1])ans++;
	//	cout<<s[i]<<' '<<s[cnt-i+1]<<endl;
	}
	cout<<ans;
	return 0;
	}
	cnt=len;
	ed=n;
	for(int l=0,i=0;l<=len/2+kkk,i<=n;i++){
		l+=k[i];
		if(l>len/2+kkk)break;
		int t=a[i];
		while(t){
			if(c[ed]==c[i]){
				if(t<a[ed]){
					cnt-=t;
					a[ed]-=t;
					break;
				//	break;
				}else {
					cnt-=a[ed];
					t-=a[ed];
					ed--;
				}
			}else{
				if(t<a[ed]){
					cnt-=t;
					ans+=t;
					a[ed]-=t;
					break;
				}else {
					ans+=a[ed];
					cnt-=a[ed];
					t-=a[ed];
					ed--;
				}	
				}
		}
	}
	cout<<ans;
	//感觉今年：橙橙橙绿，为什么T2我没调出来！！！
	//开场10分钟秒T1,T3二十分钟，T4四十分钟，过不了T2的来了（）写了个分段骗分
	//估分 100pts+[56+eps]pts+100pts+100pts;
	//今年1=线要起飞啊
	return 0;
}