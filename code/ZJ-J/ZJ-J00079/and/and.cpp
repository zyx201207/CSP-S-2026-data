#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[200005][35],t,l,ans,f[200005],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		t=0;
		while(x){
			t++;
			if(x%2==1)a[i][t]=1;
			x>>=1;
		}
		l=max(l,t);
	}
	for(int j=l;j>=1;j--){
		s=0;
		for(int i=1;i<=n;i++)
			if(f[i]==0)s+=a[i][j];
		if(s>=m){
			for(int i=1;i<=n;i++)
				if(a[i][j]==0)f[i]=1;
			ans+=1<<(j-1);
		}
	}
	cout<<ans;
	return 0;
}