#include<bits/stdc++.h>
#define ll long long
using namespace std;
//0 1 4 2 1 2 3 4      =>   1
/*
5 3
-3 0 2 3 4  =>  2
*/
ll x[2000005],d;ll n;
map<pair<ll,ll>,pair<ll,ll> > anss;

pair<ll,ll> zdR(ll a,ll b,ll leftL){ //.first方案数，.second长度 
	pair<ll,ll> ipt;ipt.first=a;ipt.second=b;
	if(anss.count(ipt)){
		pair<ll,ll> tmpans=anss[ipt];
		//cout<<"LOAD:\t"<<ipt.first<<' '<<ipt.second<<' '<<tmpans.first<<' '<<tmpans.second<<'\n';
		if(tmpans.second<=leftL) return tmpans;
	}
	if(leftL<0){
		pair<ll,ll> t;t.first=0;t.second=1e10;return t;
	}
	if(b-a==0){
		pair<ll,ll> t;t.first=1;t.second=0;return t;
	}
	ll ans=0,nowMinLen=leftL-1;
	for(int i=b;i>a;i--){
		if(x[i]-x[a]>d) continue;
		//cout<<"CALL: "<<a<<' '<<i<<' '<<b<<' '<<nowMinLen<<'\n';
		pair<ll,ll> tmp=zdR(i,b,nowMinLen);
		//cout<<"GETED\n";
		//cout<<a<<' '<<i<<'\t'<<i<<' '<<b<<' '<<tmp.first<<' '<<tmp.second<<' '<<ans<<'\n';
		if(tmp.first==0) break;
		//if(tmp.second<0) cout<<a<<' '<<i<<'\t'<<i<<' '<<b<<' '<<tmp.first<<' '<<tmp.second<<'\n';
		if(tmp.second<nowMinLen){
			nowMinLen=tmp.second;ans=tmp.first;
		}else if(tmp.second==nowMinLen) ans+=tmp.first;
	}
	pair<ll,ll> fin;fin.first=ans;fin.second=nowMinLen+1;
	if(nowMinLen!=leftL-1){
		anss[ipt]=fin;
		//cout<<"SAVE:\t"<<ipt.first<<' '<<ipt.second<<' '<<fin.first<<' '<<fin.second<<'\n';
	}
	return fin;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	short c;cin>>c;
	ll t;cin>>t;
	//t=1;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		//pair<ll,ll> t=zdR(0,4,1e10);
		//cout<<"FINALOP: "<<t.first<<' '<<t.second<<endl;
		ll ans=0; 
		for(int i=0;i<n;i++) for(int j=n-1;j>i && x[j]>x[i]+d;j--){
			pair<ll,ll> t=zdR(i,j,1e10);
			//cout<<"MAINOUTPUT: "<<i<<' '<<j<<' '<<t.first<<'\n';
			if(zdR(i,j,1e10).first==2) ans++;
		}
		cout<<ans<<'\n';
		anss.clear();
	}
	return 0;
}

