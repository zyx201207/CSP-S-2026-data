#include<bits/stdc++.h>
using namespace std;
int x,n,m,ms,s,ans,t;
bool a[200005][50];
int main(){
	freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		s=0;
		while(x>0){
			s++;
			a[i][s]=x%2;
			x/=2;
		}
		ms=max(ms,s);
	}
	for(int i=ms;i>=1;i--){
		x=0;
		for(int j=1;j<=n;j++)
			if(a[j][i]==1&&a[j][0]==0) x++;	
		if(x>=m){
			for(int j=1;j<=n;j++)
				if(a[j][i]==0) a[j][0]=1;
			t=1;
			for(int j=1;j<i;j++) t*=2;
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}