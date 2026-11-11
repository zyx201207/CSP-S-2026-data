#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}; 
int n;
long long ans;
const int N=2e5+10;
node p[N];
bool flag=true,flag1=true,flag2=true;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].a>>p[i].c;
		if(i>1 && p[i].c!=p[i-1].c)flag=false;
		if(p[i].a!=1)flag1=false;
		if(p[i].a>50)flag2=false;
	}
	if(n==1 || flag){
		cout<<0<<'\n';
		return 0;
	}
	if(flag1){
		long long cnt=0;
		for(int i=1;i<=n/2;++i){
			cnt+=(p[i].c!=p[n-i+1].c);
		}
		cout<<cnt<<'\n';
		return 0;
	}
	if(flag2){
		long long ans=0,tot=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=p[i].a;++j){
				s+=p[i].c;
			}
			tot+=p[i].a;
		}
		s=' '+s;
		long long tot1=tot;
		tot1/=2;
		for(int i=1;i<=tot1;++i){
			ans+=(s[i]!=s[tot-i+1]);
		}
		cout<<ans<<'\n';
		return 0;
	}
	long long ans=0;
	long long cnt=0,res=0,res1=0,res2=0;
	long long x=n;
	for(int i=1;i<=n;++i){
		res+=p[i].a;
	}
	long long xia=0;
	for(int i=1;i<=n;++i){
		res1+=p[i].a;
		if(res1>=res/2){
			xia=i;
			break;
		}
	}
	for(int i=1;i<=xia;++i){
		long long num=p[i].a;
		if(i==xia){
			num=res/2-res2;
		}
		while(num>0){
			if(p[i].c!=p[x].c){
				if(num>=p[x].a){
					num-=p[x].a;
					ans+=p[x].a;
					x--;
				}else {
					p[x].a=abs(p[x].a-num);
					ans+=num;
					num=0;
				}
			}else {
				if(num>=p[x].a){
					num-=p[x].a;
					x--;
				}else {
					p[x].a=abs(p[x].a-num);
					num=0;
				}
			}
		}
		res2+=p[i].a;
	}
	cout<<ans<<'\n';
	return 0;
}
