#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+9;
char x;
//ll n,b[N],cnt,fz,duan,ans;
//struct o{
//	ll l,r,sum;
//}a[N];
//vector<ll> lsh;
//map<ll,ll> mp;
//ll s[2*N],fm[2*N];
ll s,ans,n;
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ll sss,wei;
	cin>>n;
//	a[1].l=1;
	for(ll i=1;i<=n;i++){
		cin>>s>>x;
		while(s--) ss=ss+x;
//		cin>>a[i].sum>>x;
//		b[i]=x-'a'+1;
//		cnt+=a[i].sum;
//		a[i].l=a[i-1].r+1;
//		a[i].r=a[i].l+a[i].sum-1;
	}
	for(ll i=0;i<=(ss.size()+1)/2-1;i++){
		if(ss[i]!=ss[ss.size()-i-1]) ans++;
	}
	cout<<ans<<"\n";
//	if(cnt&1){
//		sss=0;
//		duan=(cnt+1)/2;
//		for(ll i=1;i<=n;i++){
//			if(a[i].l<=duan&&duan<=a[i].r){
//				fz=i;
//				break;
//			}
//		}
//	}else{
//		sss=1;
//		duan=cnt/2;
//		for(ll i=1;i<=n;i++){
//			if(a[i].l<=duan&&duan<=a[i].r){
//				fz=i;
//				break;
//			}
//		}
//	}
////-----------------------------------------------------------------------------------------------
//	for(ll i=1;i<fz;i++){
//		lsh.push_back(a[i].l);
//		lsh.push_back(a[i].r);
//	}
//	if(a[fz].r>duan) a[fz].r=2*duan-a[fz].r+sss;
//	lsh.push_back(a[fz].l);
//	lsh.push_back(a[fz].r);
//	lsh.push_back(a[fz].r+1);
//	for(ll i=fz+1;i<=n;i++){
//		a[i].l=2*duan-a[i].l+sss;
//		a[i].r=2*duan-a[i].r+sss;
//		lsh.push_back(a[i].l);
//		lsh.push_back(a[i].r);
//	}
//	sort(lsh.begin(),lsh.end());
//	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
//	for(ll i=0;i<lsh.size();i++){
//		mp[lsh[i]]=i+1;
//		fm[i+1]=lsh[i];
////		cout<<i+1<<" "<<fm[i+1]<<"\n";
//	}
////-----------------------------------------------------------------------------------------------
////	cout<<"\n\n";
//	for(ll i=1;i<fz;i++){
//		ll k1=mp[a[i].l],k2=mp[a[i].r+1],sm=b[i];
//		s[k1]+=sm;
//		s[k2]-=sm;
////		cout<<i<<" "<<k1<<" "<<k2<<" "<<sm<<"!\n";
////		for(ll i=1;i<=lsh.size();i++){
////			cout<<i<<" "<<s[i]<<"@\n";
////		}
//	}
//	ll sss1=1;
//	if(a[fz].l>a[fz].r){
//		swap(a[fz].l,a[fz].r);
//		sss1=-1;
//	}
//	wei=mp[a[fz].r+1];
//	ll kk1=mp[a[fz].l],kk2=mp[a[fz].r+1],smm=sss1*b[fz];
//	s[kk1]+=smm;
//	s[kk2]-=smm;
////	cout<<fz<<" "<<kk1<<" "<<kk2<<" "<<smm<<"!\n";
////	for(ll i=1;i<=lsh.size();i++){
////		cout<<i<<" "<<s[i]<<"@\n";
////	}
//	for(ll i=fz+1;i<=n;i++){
//		ll k1=mp[a[i].r],k2=mp[a[i].l+1],sm=-b[i];
////		if(i==fz+1&&k2<kk2) k2=kk2;
//		s[k1]+=sm;
//		s[k2]-=sm;
////		cout<<i<<" "<<k1<<" "<<k2<<" "<<sm<<"!\n";
////		for(ll i=1;i<=lsh.size();i++){
////			cout<<i<<" "<<s[i]<<"@\n";
////		}
//	}
////---------------------------------------------------------------------------------------------------
//	ll od=0;
//	for(ll i=1;i<=lsh.size();i++){
//		s[i]+=s[i-1];
//		ll nw=fm[i];
//		if(i==wei) break;
////		cout<<i<<" "<<od<<" "<<nw<<"?\n";
//		ans+=((s[i])?nw-od:0);
//		od=nw;
//	}
////	cout<<duan<<"\n\n";
////	for(ll i=1;i<=lsh.size();i++){
////		cout<<i<<" "<<s[i]<<" "<<fm[i]<<"@\n";
////	}
////	cout<<"\n\n";
////	for(ll i=1;i<=n;i++){
////		cout<<i<<" "<<a[i].l<<" "<<a[i].r<<"*\n";
////	}
//	cout<<ans<<"\n";
	return 0;
}
/*
3
2 a
2 b
1 c

6
100 a
100 a
100 a
100 b
100 b
100 b
*/
