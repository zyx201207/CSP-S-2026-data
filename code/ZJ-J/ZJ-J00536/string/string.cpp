#include<bits/stdc++.h>
using namespace std;
int n,x;
char y;
long long l=1,ans=0;
struct m_p{
	long long s;
	long long e;
	char na;
}mp[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(y==mp[i-1].na){
			i--;n--;
			mp[i].e+=x;
			l+=x;
			continue;
		}
		mp[i].s=l;
		l+=x;
		mp[i].e=l-1;
		mp[i].na=y;
	}
	long long le=1,ri=l-1,nl=1,nr=n;
	while(ri>le&&nl!=nr){
		if(mp[nl].e>mp[nr].s){
			if(mp[nl].na!=mp[nr].na) ans+=mp[nr].e-mp[nr].s+1;
			mp[nl].s+=mp[nr].e-mp[nr].s+1;
			le=mp[nl].s;
			nr--;
			ri=mp[nr].e;
		}
		else if(mp[nl].e<mp[nr].s){
			if(mp[nl].na!=mp[nr].na) ans+=mp[nl].e-mp[nl].s+1;
			mp[nr].e-=mp[nl].e-mp[nl].s+1;
			ri=mp[nr].e;
			nl++;
			le=mp[nl].s;
		}
		else{
			if(mp[nl].na!=mp[nr].na) ans+=mp[nl].e-mp[nl].s+1;
			nl++;
			nr++;
			le=mp[nl].s;
			ri=mp[nr].e;
		}
	}
	cout<<ans;
}
