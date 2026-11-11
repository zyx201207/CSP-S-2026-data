#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long sum,ans;
struct abc{
	long long a;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		sum+=a[i].a;
	}
	long long l=1,r=n,lastl=0,lastr=0,nowl=a[1].a,nowr=a[n].a,bjl=0,bjr=sum;
	while(l<r){
		if(a[l].c==a[r].c){
			if(nowl<nowr){
				l++;
				nowl+=a[l].a;
				lastl+=a[l-1].a;
				bjl+=a[l].a;
			}
			else if(nowr<nowl){
				r--;
				nowr+=a[r].a;
				lastr+=a[r+1].a;
				bjr-=a[r].a;
			}
			else{
				l++;
				nowl+=a[l].a;
				lastl+=a[l-1].a;
				bjl+=a[l].a;
				r--;
				nowr+=a[r].a;
				lastr+=a[r+1].a;
				bjr-=a[r].a;
			}
		}
		else{
			if(nowl<nowr){
				ans+=nowl-max(lastl,lastr);
				l++;
				nowl+=a[l].a;
				lastl+=a[l-1].a;
				bjl+=a[l].a;
			}
			else if(nowl>nowr){
				ans+=nowr-max(lastl,lastr);
				r--;
				nowr+=a[r].a;
				lastr+=a[r+1].a;
				bjr-=a[r].a;
			}
			else{
				ans+=nowr-max(lastl,lastr);
				l++;
				nowl+=a[l].a;
				lastl+=a[l-1].a;
				bjl+=a[l].a;
				r--;
				nowr+=a[r].a;
				lastr+=a[r+1].a;
				bjr-=a[r].a;
			}
		}
//		cout<<nowl<<' '<<nowr<<'\n';
//		cout<<l<<' '<<r<<'\n';
//		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
5
3 a
3 b
2 c
5 a
1 b
*/
