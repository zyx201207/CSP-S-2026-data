#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int mx=0;
struct ovo{
	int sj;
	string rhl;
}a[N];
string solve(int q){
	string s="";
	while(q){
		s=to_string((q%2))+s;
		q/=2;
	}
	return s;
}
bool cmp(const ovo &b,const ovo &c){
	return b.rhl>c.rhl;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int ans;
	for(int i=1;i<=n;i++){
		cin>>a[i].sj;
		a[i].rhl=solve(a[i].sj);
		if(i==1) ans=a[i].sj;
		else ans&=a[i].sj;
		mx=max(mx,a[i].sj);
	}
	if(m==1){
		cout<<mx<<"\n";
		return 0;
	}
	if(m==n){
		cout<<ans<<"\n";
		return 0;
	}
	if(n<=20){
		int gh=0;
		for(int mark=0;mark<(1<<n);mark++){
			int jk=-1;
			int cnt=0;
			for(int j=0;j<n;j++){
				if((1<<j)&mark){
					cnt++;
					if(jk==-1){
						jk=a[j+1].sj;
					}else jk&=a[j+1].sj;
				}
			}
			if(cnt==m){
				gh=max(gh,jk);
			}
		}
		cout<<gh<<"\n";
		return 0;
	}
	if(m==2&&n<=2000){
		int gh=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				gh=max(gh,(a[i].sj&a[j].sj));
			}
		}
		cout<<gh<<"\n";
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int y[31];
	memset(y,0,sizeof y);
	for(int i=1;i<=m;i++){
	//	cout<<a[i].rhl<<"\n";
		for(int j=0;j<a[i].rhl.size();j++){
			//cout<<(a[i].sj>>j)<<" "<<j<<"\n";
		//	cout<<a[i].rhl[j]<<"\n";
			y[a[i].rhl.size()-j-1]+=a[i].rhl[j]-'0';
		}
	}
	int sum=0;
	for(int i=0;i<=30;i++){
		if(y[i]==m){
			sum+=(1<<i);
		}
	}
	cout<<sum<<"\n";
	return 0;
}
