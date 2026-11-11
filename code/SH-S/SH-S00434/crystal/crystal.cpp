#include <bits/stdc++.h>
using namespace std;
int n;
long long m,ans=1,maxai=0;
long long a[500005];
void solve1() {
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		long long now=a[i],cst=0,cnt=1;
		for(int j=i-1;j>=1;j--) {
			if(cst>=m) {
				if(cst>m) cnt--;
				break;
			}
			cst+=now-a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
int cnt[205];
const int MOV=101;
vector<pair<long long,long long> > num;
void solve2() {
	for(int i=1;i<=201;i++) {
		if(!cnt[i]) continue;
		num.push_back(make_pair(i,cnt[i]));
	}
	int siz=num.size();
	for(int i=0;i<siz;i++) {
		long long now=num[i].first,cst=0,cnt=num[i].second;
		for(int j=i-1;j>=0;j--) {
			long long tmp=m-cst,spd=now-num[j].first,snum=min(tmp/spd,num[j].second);
			cnt+=snum;
			cst+=spd*snum;
			if(snum==0) break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
long long s_one_i(int i) {
	long long res=1LL*(1+i)*i/2;
	return res;
}
long long dcsl(long long fir,long long lst,int xs) {
	long long res=(fir+lst)*xs/2;
	return res;
}
void solveA() {
	long long cnt=1;
	for(int i=1;i<=n-1;i++) {
		if(s_one_i(i)<=m) cnt++;
	}
	cout<<cnt;
}
void solveB() {
	long long cnt=1,gc=a[2]-a[1];
	for(int i=1;i<=n-1;i++) {
		if(dcsl(gc,i*gc,i)<=m) cnt++;
	}
	cout<<cnt;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool A=1,B=1; 
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cnt[a[i]+MOV]++;
		maxai=max(maxai,abs(a[i]));
		if(a[i]!=i&&A) A=0;
	}
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) {
			B=0;
			break;
		}
	if(n<=5000) {
		solve1();
	} else if(maxai<=100) {
		solve2();
	} else if(A) {
		solveA();
	} else if(B) {
		solveB();
	}
	return 0;
}
