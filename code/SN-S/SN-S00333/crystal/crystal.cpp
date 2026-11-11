//李方骁 西安交通大学附属中学 SN-S00333 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll m;
ll a[500005],jc,mhf;
ll cha[500005],hf;
ll dip;//丢掉的位置 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(ll i=1;i<=n;++i)cout<<a[i]<<' ';
	for(ll i=1;i<n;++i){
		cha[i]=a[i+1]-a[i];
	}
//	for(ll i=1;i<n;++i)cout<<cha[i]<<' ';
	hf=m;
	jc=1;
	dip=0;
	for(ll i=1;i<n;++i){
		if(hf>=jc*cha[i]){
			hf-=jc*cha[i];
			jc++;
			mhf+=cha[i];
//			cout<<hf<<'\n';
		}
		else{
			dip++; 
			hf+=mhf;
			mhf-=cha[dip];
			hf-=(jc-1)*cha[i];
			mhf+=cha[i];
		}
	}
	cout<<jc;
	return 0;
}
