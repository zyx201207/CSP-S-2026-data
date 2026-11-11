#include<bits/stdc++.h>
using namespace std;
int n,m,s1,a[200005];
bool f[200005][35],r[200005],ans[37];
bool fdsd(int a,int b){return a>b;}
void er(int p,int x){
	int t=0;
	while(x>0)f[p][++t]=x%2,x/=2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,fdsd);
	for(int i=1;i<=n;i++)er(i,a[i]);
	for(int i=1;i<=n;i++)r[i]=1;
	for(int j=30;j>=1;j--){
		int s=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]==1&&r[i])s++;
		}
		if(s>=m){
			ans[j]=1;
			for(int i=1;i<=n;i++)
				if(!f[i][j])r[i]=0;
		}
	}
	for(int i=1,a=1;i<=30;i++)
		s1+=a*ans[i],a*=2;
	cout<<s1;
	return 0;
}
//rp++
/*
5 3
31 3 1 15 7
4 2
3 15 12 12
ccf's problem is too hard
??9:38 AC??
??10:30 WA??
??10:30 AC??
*/
