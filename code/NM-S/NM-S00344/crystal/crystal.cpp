#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,l=0,res,ans=0;
ll m,c=0,cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<ll>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<=5000){
		sort(a.begin(),a.end());
		for(int r=0;r<n;r++){
			l=r,res=0,c=0;
			while(l>=0 && c+(a[r]-a[l])<=m){
				c+=a[r]-a[l];
				l--;
				res++;
				if(c<cnt[res]) cnt[res]=c;
				else continue;
			}
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	}else{
		vector<ll>s(n);
		for(int i=0;i<n;i++) s[i]=abs(a[i]-a[0]);
		int p=0;
		for(int i=0;i<n;i++){
			if(m-s[i]>=0) p++,m-=s[i];
			else break;
		}
		cout<<p<<endl;
	}
	return 0;
}


