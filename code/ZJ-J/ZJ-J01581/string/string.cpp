#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mcx=2e5+5;
int n,len,ans,cnt,l[mcx],r[mcx],x[mcx],ccnt[30];
char c[mcx];
struct xu{
	int l,r,x;
	char c;
	bool operator <(const xu &B)const{return l<B.l;}
}a[mcx];
class SUBFF{
public:
	void work(){
		string s="";
		for(int i=1;i<=n;i++)for(int j=1;j<=a[i].x;j++){
			s=s+a[i].c;
		}
		for(int i=1;i<=s.size()/2;i++){
			if(s[i]!=s[s.size()-i+1])ans++;
		}
		cout<<ans<<'\n';
	}
}subfif;
class SUBEX{
public:
	void calc(int lft,int rit){
		memset(ccnt,0,sizeof ccnt);
		int li=lower_bound(l+1,l+n+1,lft)-l;
		int ri=lower_bound(l+1,l+n+1,rit)-l;
		for(int i=lft;i<a[li].l;i++)ccnt[a[li-1].c-'a']++;
		for(int i=rit;i<a[ri].l;i++)ccnt[a[ri-1].c-'a']++;
		for(int i=li;i<(a[ri].l>rit?ri-1:ri);i++)ccnt[a[i].c-'a']+=a[i].x;
	}
	void work(){
		if(len&1){
			int mid=len/2+1,i=0,lenth=0;
			while(a[++i].x+lenth<mid)lenth+=a[i].x;
			for(int j=1;j<=i;j++){
				int need=a[j].x;
				calc(n-a[j].l+1,n-a[j].r+1);
				for(int k=0;k<=25;k++){
					if(k==(int)(a[i].c-'a'))need-=ccnt[k];
				}
				ans+=need;
			}
		}
		else{
			int mid=len/2,i=0,lenth=0;
			while(a[++i].x+lenth<=mid)lenth+=a[i].x;
			for(int j=1;j<=i;j++){
				int need=a[j].x;
				calc(n-a[j].l+1,n-a[j].r+1);
				for(int k=0;k<=25;k++){
					if(k==(int)(a[i].c-'a'))need-=ccnt[k];
				}
				ans+=need;
			}
		}
		cout<<n-ans+1<<'\n';
	}
}subx;
class SUBBBB{
	public:
	void work(){
		int mid=n/2,ans=0;
		for(int i=1;i<=mid;i++){
			if(a[i].c!=a[n-i+1].c)ans+=a[i].x;
		}
		cout<<ans<<'\n';
	}
}sub;
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=1,_;
	for(int i=1;i<=n;i++){
		int now;
		char ch;
		cin>>now>>ch;
		if(i==1)_=now;
		if(now!=_)f=0;
		a[i]={len+1,len+now-1,now,ch};
		l[i]=a[i].l;
		r[i]=a[i].r;
		x[i]=a[i].x;
		c[i]=a[i].c;
		len+=now;
	}
	if(len<=1e8){
		subfif.work();
		return 0;
	}
	else{
		subx.work();
		return 0;
	}
	return 0;
}
