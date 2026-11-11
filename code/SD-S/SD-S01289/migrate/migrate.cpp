#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define INF 1e9
ll c,t,n,d,x,lx,a[2000005],ss;
ll l[2000005][2];
//void s(ll l,ll m,ll st){
//	if(st>mn)return;
//	if(l==m){
//		if(st<mn){
//			ss=1;
//			mn=st;
//		}else if(st==mn)
//		{
//			ss++;
//		}
//		return;
//	}
//	ll di=0;
//	for(ll i = l+1;i<=m;i++){
//		di+=a[i-1];
//		if(di>d)break;
//		s(i,m,st+1);
//	}
//}
//ll s(ll st,ll m){
//	ll mn=INF;
//	ll l[2000005][2]={};
//	l[st][1]=1;
//	for(ll i = st+1;i<=m;i++)l[i][0]=INF;
//	for(ll i = st;i<=m;i++){
//		ll di=0;
//		for(ll j = i+1;j<=m;j++){
//			di+=a[j-1];
//			if(di>d)break;
////			cout << i << ',' << j << ',' << l[i][0] << ',' << l[i][1] << ',' << l[j][0] << ',' << l[j][1] << ' ';
//			if(l[j][0]>l[i][0]+1){
//				l[j][0]=l[i][0]+1;
//				l[j][1]=l[i][1];
//			}else if(l[j][0]==l[i][0]+1){
//				l[j][1]+=l[i][1];
//			}else{
//				break;
//			}
//		}
//	}
//	return l[m][1];
//}
int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(ll crtlp=0;crtlp<t;crtlp++){
		cin >> n >> d;
		cin >> lx;
		for(ll i = 1;i<n;i++){
			cin >> x;
			a[i]=x-lx;
			lx=x;
		}
		ll r[2000005]={};
		ll ct=0;
		for(ll i = 1;i<n-2;i++){
			for(ll j = i+3;j<=n;j++){
//				cout << i << ' ' << j << endl;
				l[i][1]=1;
				l[i][0]=0;
				for(ll ww = i+1;ww<=j;ww++)l[ww][0]=INF;
				
				for(ll ww = i;ww<j;ww++){
					ll di=0;
					for(ll wq = ww+1;wq<=j;wq++){
						di+=a[wq-1];
						if(di>d)break;
//						cout << i << ',' << j << ',' << l[i][0] << ',' << l[i][1] << ',' << l[j][0] << ',' << l[j][1] << ' ';
						if(l[wq][0]>l[ww][0]+1){
							l[wq][0]=l[ww][0]+1;
							l[wq][1]=l[ww][1];
						}else if(l[wq][0]==l[ww][0]+1){
							l[wq][1]+=l[ww][1];
						}
						
					}
				}
				ss=l[j][1];
				if(ss==2){
					ct++;
					break;
				}
				if(ss==3)break;
			}
		}
		cout << ct << endl;
//		cout << endl << ct << endl << endl;
	}
	return 0;
} 
