#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ull unsigned long long
using namespace std;
const int N=2e5+50;
map<char,ll>mpq;
map<char,ll>mph;
int n;
ll a[N];
char c[N];
ll qb,hb;
ll ans;
int gcd(ll x,ll y){
	if(x<y)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y); 
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	ll gc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//sum[i]=sum[i-1]+a[i];
		gc=gcd(gc,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]/=gc;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string s1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<int((s.size())+1)/2;i++){
		if(s[i]!=s1[i])ans++;
	}
	cout<<ans*gc<<endl;
	/*ll zd=(sum[n]+1)/2;
	for(int i=1;i<=n;i++){
		if(sum[i]>=zd){
			if(sum[n]%2==1){
				qb=zd-sum[i-1];
				hb=sum[i]+1-zd;
			}
			else{
				qb=zd-sum[i-1];
				hb=sum[i]-zd;
			}
			zdi=i;
			break;
		}
	}*/
	//cout<<zdi<<'/'<<c[zdi]<<":"<<qb<<' '<<hb;
	/*123456
	abcdef
	2 4 5
	aabbc
	aab bbc
	cbb
	cbb
	2a1b
	1c2b
	2 5  6
	aabbbc
	3  5 7
	aaabbcc
	1 4 5
	abbbc
	3  45
	aaabc
	aaabbb
	bbb
	*/
	/*for(int i=1;i<=n;i++){
		if(i!=zdi){
			if(sum[i]<zd){
				mpq[c[i]]+=a[i];
			}
			else{
				mph[c[i]]+=a[i];
			}
		}
		else{
			mpq[c[i]]+=qb;
			mph[c[i]]+=hb;
		}
	}
	ll ans=0;
	for(auto it:mph){
		ans+=abs(it.second-mpq[it.first]);
		//cout<<it.first<<':'<<it.second<<' '<<mpq[it.first]<<endl;
	}*/
	//cout<<min(zd,ans);
	/*for(auto i:mpq){
		cout<<i.first<<':'<<i.second<<endl;
	}
	cout<<"///////////\n";
	for(auto it:mph){
		cout<<it.first<<':'<<it.second<<endl;
	}*/
    return 0;
}
//hao jue wang a,xie le ban tian zheng jie ,jie guo shi jia de
