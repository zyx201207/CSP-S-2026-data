#include<bits/stdc++.h>
using namespace std;

const int M=5e5+5;

long long n,tot;
long long cnta,cntb,m,ans=1LL;
long long a[M],c[M];
int t[M];

int main(){
	freopen("crystal2.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	int pos=1;
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]!=0){
			pos=i;
			t[i]=1;
		}else{
			t[pos]++;
		}
	}

	for(int i=2;i<=n;i++){
		cntb=cnta+c[i]*(i-1);
		if(cntb<=m){
			cnta=cntb;
			ans++;			
		}
		if(a[i]!=a[i-1]){
			if(cntb>m){
				int cost=(m-cnta)/c[i];
				ans=max(ans,1LL*cost+1LL*t[i]);
				break;
			}
		}	
	}
	
	cout<<ans;
	
  fclose(stdin);
	fclose(stdout);
	return 0;
}

