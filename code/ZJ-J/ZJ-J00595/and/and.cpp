#include<bits/stdc++.h>
using namespace std;
int n,m;
string s2;
bool f[233],ff[200010];
int ll=0;
long long int d,x,mod=1e16;
struct p{
	string a,s;
}a[200010];
bool cmp(p aa,p bb){
	return aa.s>bb.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){x=d=0;
		cin>>a[i].a;
		s2=' ';
		a[i].s=' ';
		for(int j=0;j<a[i].a.size();j++){
			x=x*10+(a[i].a[j]-'0');
			d=d*10+x/mod;
			x%=mod;
		}//cout<<d<<x<<"\n";
		while(x>0||d>0){
			s2+=(x%2+'0');
			x+=d%2*10;
			d/=2;
			x/=2;
			
		}
//		for(int j=0;j<a[i].a.size();j++){
//			ss[a[i].a.size()-j-1]=a[i].a[j]-'0';
//		}int ll=a[i].a.size()-1;
//		
//		while(ll>=0){
//			s2+=(ss[0]%2+'0');
//			for(int j=ll;j>=0;j--){
//				ss[j-1]+=ss[j]%2*10;
//				ss[j]/=2;
//				if(ss[j]==0)ll--;
//			}
//		}
//		ll=0;
	//cout<<s2<<"\n";
		for(int j=1;j<s2.size();j++){
			a[i].s+=s2[s2.size()-j];
			//cout<<a[i].s[s2.size()-j]<<" ";
		}
		ll=max(ll,(int)a[i].s.size());
	}//cout<<ll<<"\n";
	for(int k=ll-1;k>=1;k--){
		int z=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i].s<<" "<<a[i].s.size()-k<<" "<<(a[i].s[a[i].s.size()-k]=='1')<<"\n";
			if(ff[i]==0&&a[i].s.size()>=k+1){
				if(a[i].s[a[i].s.size()-k]=='1')z++;
			}
		}//cout<<z<<"\n";
		if(z>=m){
			f[k]=1;
			for(int i=1;i<=n;i++){
				if(ff[i]==0&&a[i].s.size()>=k+1){
					if(a[i].s[a[i].s.size()-k]=='0')ff[i]=1;
				}
				else ff[i]=1;
			}
		}
	}x=d=0;
	for(int i=0;i<=31;i++){
		//cout<<i<<":"<<f[i]<<"\n";
		if(f[i]==0)continue;
		long long int xx=1,dd=0;
		for(int j=1;j<i;j++){
			dd*=2,xx*=2;
			dd+=(xx/mod);
			xx%=mod;
		}
		d+=dd,x+=xx;
		d+=(x/mod);
		x%=mod;
	}
	if(d>0){
		printf("%lld%.15lld",d,x);
	}
	else printf("%lld",x);
	return 0;
}//4 2 3 15 12 12