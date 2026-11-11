#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct node{
	ll a,t;
};
ll c,n,m,d,q,w[500005],k[505];
vector<node>s[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll z,h;
			cin>>z>>h;
			s[i].push_back({z,h});
		}
	}
	if(n==2){
		while(q--){
			ll xy=0,xe=0,yy=0,ye=0,x,y,zhong=0x3f3f3f3f,xyb,xeb,yyb,yeb,answ,yi=0,er=0;
			cin>>x>>y;
		for(int i=0;i<s[1].size();i++){
			if(s[1][i].a==x){
				xy=1;
				xyb=i;
				yi+=s[1][i].t;
			}
			if(s[1][i].a==y){
				yy=1;
				yyb=i;
				er+=s[1][i].t;
			}
		}
		for(int i=0;i<s[2].size();i++){
			if(s[2][i].a==x){
				xe=1;
				xeb=i;
				er+=s[2][i].t;
			}
			if(s[2][i].a==y){
				ye=1;
				yeb=i;
				yi+=s[2][i].t;
			}
		}
		for(int i=0;i<s[1].size();i++){
			for(int j=0;j<s[2].size();j++){
				if(s[1][i].a==s[2][j].a){
					ll sum=s[1][i].t+s[2][j].t;
					if(sum<zhong){
						zhong=sum;
					}
				}
			}
		}
		ll minn=0x3f3f3f3f;
		if(xy==1&&xe==1&&yy==1&&ye==1){
		if(yi>er){
			minn=er;
		}else{
			minn=yi;
		}	
		}else if(xy==1&&ye==1){
			minn=yi;
		}else{
			minn=er;
		}
		answ=zhong+minn+w[x]+w[y];
			for(int i=1;i<=n;i++){
			ll flagx=0,flagy=0,sum=0;
			for(int j=0;j<s[i].size();j++){
				if(s[i][j].a==x){
					flagx=1;
				}
				if(s[i][j].a==y){
					flagy=1;
				}
			}
			if(flagx==1&&flagy==1){
				for(int j=0;j<s[i].size();j++){
				if(s[i][j].a==x){
					sum+=s[i][j].t;
				}
				if(s[i][j].a==y){
					sum+=s[i][j].t;
				}
			}
		}
		sum=sum+w[x]+w[y];
		if(sum<answ&&flagx==1&&flagy==1){
			answ=sum;
		}
	}
		cout<<answ<<'\n';
}
}else{
	while(q--){
		ll x,y,ans=0x3f3f3f3f;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			ll flagx=0,flagy=0,sum=0;
			for(int j=0;j<s[i].size();j++){
				if(s[i][j].a==x){
					flagx=1;
				}
				if(s[i][j].a==y){
					flagy=1;
				}
			}
			if(flagx==1&&flagy==1){
				for(int j=0;j<s[i].size();j++){
				if(s[i][j].a==x){
					sum+=s[i][j].t;
				}
				if(s[i][j].a==y){
					sum+=s[i][j].t;
				}
			}
		}
		sum=sum+w[x]+w[y];
		if(sum<ans){
			ans=sum;
		}
	}
	cout<<ans<<'\n';
}
}
	return 0;
}
