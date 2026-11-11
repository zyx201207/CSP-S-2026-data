#include <bits/stdc++.h>
#define ioss ios::sync_with_stdio(0);cin.tie(0);
#define ret return
#define ll long long
using namespace std;
int n;
string s;
ll a[200001];
char c[200001];
//ll b[200001],x;
//char d[200001];
//ll e[200001];
//char f[200001];
//vector<ll> g;
//vector<char> h;
ll ans;
ll sum;
//void work(){
//	ll half=sum/2;
//	ll sumq=0;
//	ll x1=0,x2=0,fkd,ccf=0;
//	for(int i=1;i<=x;i++){
//		sumq+=b[i];
//		e[++x1]=b[i];
//		f[x1]=d[i];
//		if(sumq==half){
//			fkd=i;
//			break;
//		}
//		if(sumq>half){
//			ll cc=half-sumq;
//			sumq-=b[i];
//			e[x1]=half-sumq;
//			g.push_back(b[i]-(half-sumq));
//			h.push_back(d[i]);
//			fkd=i;
//			ccf=1;
//			break;
//		}
//	}
//	for(int i=fkd+1;i<=x;i++){
//		g.push_back(b[i]);
//		h.push_back(d[i]);
//	}
//	reverse(g.begin(),g.end());
//	reverse(h.begin(),h.end());
////	for(int i=1;i<=x2;i++) cout<<g[i]<<' '<<h[i]<<'\n';
//	int j=0;
//	ll cc,bj;
//	for(int i=1;i<=x1;i++){
//		if(e[i]>g[j]){
//			cc=e[i]-g[j];
//			if(f[i]!=h[i]) ans+=e[i]-g[j];
//			for(int k=j+1;k<g.size();k++){
//				cc-=g[j];
//				if(cc<0){
//					bj=k;
//					g[k]=-cc;
//				}
//				if(cc==0){
//					g[k]=0;
//					bj=k;
//				}
//			}
//		}else if(e[i]==g[j]){
//			if(f[i]!=h[i]) ans+=e[i];
//			bj
//		}
//	}
//	
//}
int main(){
	ioss
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
//	b[++x]=a[1];
//	d[x]=c[1];
//	for(int i=2;i<=n;i++){
//		if(c[i]==c[i-1]){
//			b[x]+=a[i];
//			d[x]=c[i];
//		}else{
//			b[++x]=a[i];
//			d[x]=c[i];
//		}
//	}
//	for(int i=1;i<=x;i++) cout<<b[i]<<' '<<d[i]<<'\n';
//	work();
	ll l=s.size();
	ll mid=l/2;
	int pp=0;
	s=' '+s;
	string s1,s2;
	for(int i=1;i<=mid;i++){
		s1+=s[i];
	}
	if(l%2) pp=1;
	for(int i=mid+1+pp;i<=l;i++){
		s2+=s[i];
	}
	for(int i=0,j=s2.size()-1;i<s1.size();i++,j--){
		if(s1[i]!=s2[j]) ans++;
	}
	cout<<ans;
	return 0;
}
//freopen();