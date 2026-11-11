#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=5e5+5;
const int INF=1e18+9;
int n,m;
int a[N];
int c,pre;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f1=1,f2=1;
	int b=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=i) f1=0;
		if(i>1&&a[i]-a[i-1]!=b) f2=0;
	} 
	if(f1){
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=i*(i-1)/2;
			if(x<=m) ans=i;
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(f2){
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=i*b*(i-1)/2;
			if(x<=m) ans=i;
			else break;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int cnt=1,ans=1;
	int p=2;
	for(int i=2;i<=n;i++){
		int cc=a[i]-a[i-1];
		c+=cc;
		pre=pre+cc*cnt;
		while(pre>m){
			cnt--;
			pre-=c;
			c-=a[p]-a[p-1];
			p++;
		}
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}






//14:17 简陋的安检。。。之前还用金属探测仪敷衍地扫两下来着怎么这次演都不演了
//上厕所也不用带着准考证了，老大咱这真是正规正式考试不 
//rp++ 
//15:00假了。why 
//15:10 真了？？ 
//15:11 后悔没有好好练对拍。
//15:12 不放心，再笔算一次。
//我真感觉我时间复杂度不对啊。 
//我真后悔没复习对拍了。不管了。
//90pts-100pts 
