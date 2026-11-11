#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,maxn=0;
int a[1000010];
char h[1000010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>h[i];
		cnt+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn<=500){
		string s;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=h[i];
			}
		}
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			}
		}
		cout<<ans/2;
	}else{
		cnt/=2;
		queue<pair<int,char> > q1,q2;
		int l=1,r=n,ll=0,rr=0,lll=0,rrr=0;
		while(ll<cnt){
			lll=ll;
			ll+=a[l];
			if(ll<=cnt){
				q1.push({a[l],h[l]});
			}else{
				break;
			}
			l++;
		}
		if(ll>cnt){
			int e=cnt-lll;
			q1.push({e,h[l]});
		}
		while(rr<cnt){
			rrr=rr;
			rr+=a[r];
			if(rr<=cnt){
				q2.push({a[r],h[r]});
			}else{
				break;
			}
			r--;
		}
		if(rr>cnt){
			int e=cnt-rrr;
			q2.push({e,h[r]});
		}
	//	while(!q1.empty()){
	//		cout<<q1.front().first<<" "<<q1.front().second<<endl;
	//		q1.pop();
	//	}
	//	cout<<endl;
	//	while(!q2.empty()){
	//		cout<<q2.front().first<<" "<<q2.front().second<<endl;
	//		q2.pop();
	//	}
	//	return 0;
		int ans=0;
		while(!q1.empty()&&!q2.empty()){
			auto x=q1.front();
			auto y=q2.front();
			int xx=x.first;
			int yy=y.first;
			q1.pop();
			q2.pop();
			if(x.second!=y.second){
				int e=min(xx,yy);
				ans+=e;
				xx-=e;
				yy-=e;
			}else{
				int e=min(xx,yy);
				xx-=e;
				yy-=e;
			}
			x.first=xx;
			y.first=yy;
			if(xx!=0){
				q1.push({xx,x.second});
			}
			if(yy!=0){
				q2.push({yy,y.second});
			}
		}
		cout<<ans;
	}
	return 0;
}
