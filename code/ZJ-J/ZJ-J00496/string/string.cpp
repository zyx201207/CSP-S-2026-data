#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],s[N],md,ans=0;
char c[N];
vector<vector<int> > b(N,vector<int>(30));
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	s[0]=0;
	for(int j=1;j<=26;j++){
		b[0][j]=0;
	}for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
		for(int j=1;j<=26;j++){
			b[i][j]=b[i-1][j];
		}b[i][(int)(c[i]-'a'+1)]+=a[i];
	}md=s[n]/2;
	for(int i=1;i<=n;i++){
		int l=s[i-1]+1,r=s[i];
		if(l>md)break;
		if(r>md)r=md;
		int rr=s[n]-l+1,rl=s[n]-r+1;
		int el=lower_bound(s+1,s+n+1,rl)-s;
		int er=lower_bound(s+1,s+n+1,rr)-s;
		if((el>n||er>n)||el>er){
			break;
		}
//		cout<<l<<' '<<r<<' '<<rl<<' '<<rr<<' '<<el<<' '<<er<<'\n';
			int ic=(int)(c[i]-'a'+1);
			for(int i=1;i<=26;i++){
				if(i==ic)continue;
				int num=b[er][i]-b[el-1][i];
				if(num<=0)continue;
//				num-=s[er]-rr;
//				num-=rl-(s[el-1]+1);
				if(num>0)ans+=num;
			}
			if(c[er]!=c[i]){
				ans-=s[er]-rr;
			}if(c[el]!=c[i]){
				ans-=rl-(s[el-1]+1);
			}
	}cout<<ans;
	return 0;
}
