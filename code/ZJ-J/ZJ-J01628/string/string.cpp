#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt,n;
int ans;
const int N=2e5+10;
int l[N],r[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>c[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+x-1;
		cnt+=x;
	}
	if(cnt&1){
		int lc=1;
		int rc=cnt;
		int lk=1;
		int rk=n;
		while(lc<rc){
			int lcc=r[lk];
			int rcc=l[rk];
//			cout<<lc<<' '<<lcc<<' '<<rc<<' '<<rcc<<'\n';
			if(lcc-lc>rc-rcc){
//				cout<<"lll\n";
				if(c[lk]!=c[rk]){
					ans+=rc-rcc+1;
//					cout<<ans<<'\n';
				}
				lc+=rc-rcc;
				rc=rcc;
				lc++;
				rc--;
				rk--;
			}
			else if(lcc-lc<rc-rcc){
//				cout<<"rrr\n";
				if(c[lk]!=c[rk]){
					ans+=lcc-lc+1;
//					cout<<ans<<'\n';
				}
				rc-=lcc-lc;
				lc=lcc;
				lc++;
				rc--;
				lk++;
			}
			else{
//				cout<<"mmm\n";
				if(c[lk]!=c[rk]){
					ans+=(lcc-lc+1);
				}
				lc=lcc;
				rc=rcc;
				lc++;
				rc--;
				lk++;
				rk--;
			}
		}
	}
	else{
		int lc=1;
		int rc=cnt;
		int lk=1;
		int rk=n;
		while(rc>lc+1){
//			cout<<123;
			int lcc=r[lk];
			int rcc=l[rk];
			if(lcc-lc>rc-rcc){
//				cout<<123;
				if(c[lk]!=c[rk])ans+=rc-rcc+1;
				lc+=rc-rcc;
				lc++;
				rc--;
				rk--;
			}
			else if(lcc-lc<rc-rcc){
//				cout<<123;
				if(c[lk]!=c[rk])ans+=lcc-lc+1;
				rc-=lcc-lc;
				lc++;
				rc--;
				lk++;
			}
			else{
//				cout<<123;
				if(c[lk]!=c[rk])ans+=(lcc-lc+1);
				lc=lcc;
				rc=rcc;
				lc++;
				rc--;
				lk++;
				rk--;
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}
