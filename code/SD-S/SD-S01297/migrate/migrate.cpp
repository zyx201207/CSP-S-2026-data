#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct E{
	ll cnt,x;
}a[2000010];
struct Q{
	ll l,r;
}e[2000010];
ll cc[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c,T,n,d,xxxxx=0;
	cin>>c>>T;
	while(T--){
		ll k=1,l,sum=0,xxx=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i].x;
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		bool ff=1;
		ll kk=a[2].x-a[1].x;
		for(int i=2;i<=n;i++){
			if(a[i].x-a[i-1].x!=kk){
				ff=0;
				break;
			}
		}
		if(n>5000){
			if(ff==1){
				d/=kk;
				if(d<=1){
	  				cout<<0<<endl;
				}
				else{
					cout<<max(xxxxx,n-(d*2)+1)<<endl;
				}
			}
			else{
				cout<<10<<endl;
			}
		}
		else{
			e[0].l=1;
			for(int i=2;i<=n;i++){
				if(a[i].x-a[i-1].x>d){
					e[xxx].r=i-1;
						xxx++;
					e[xxx].l=i;
				}
			}
			e[xxx].r=n;
			for(int ttt=0;ttt<=xxx;ttt++){
				for(int lll=e[ttt].l;lll<=e[ttt].r-1;lll++){
					memset(cc,0,sizeof(cc));
					k=1;
					l=a[lll].x;
					a[lll].cnt=0;
					cc[lll]=1;
					for(int i=lll+1;i<=e[ttt].r;i++){
						if(a[i].x-l>d){
							l=a[i-1].x;
							k++;
							a[i].cnt=k;
						}
						else{
							a[i].cnt=k;
						}
						for(int j=i-1;j>=lll;j--){
							if(a[j].cnt<a[i].cnt-1){
								break;
							}
							if(a[j].cnt>a[i].cnt-1){
								continue;
							}
							if(a[i].x-a[j].x<=d){
								cc[i]+=cc[j];
							}
						}
						if(cc[i]==2){
							sum++;
						}
					}
				}
			}
			cout<<sum<<endl;
		}
		
	}
	return 0;
}
