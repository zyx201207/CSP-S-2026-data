#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,cnt,w,ans,c1,c2,c3,c4;
int a[200001],s[200001];
void dfs(int s){
	if(k==m){
		ans=max(cnt,ans);
		return;
	} 
	for(int i=s+1;i<=n;i++){
		w=cnt;
		cnt=cnt&a[i];
		k++;
		dfs(i);
		k--;
		cnt=w;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=-1;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cnt=a[i];
			dfs(i);
			k=1;
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			cout<<a[n];
			return 0;
		}
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans*=a[i];
			}
			cout<<ans;
			return 0;
		}
		if(m==2){
			ans=0;
			int y=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[i-1]) s[++y]=a[i];
			}
			for(int i=1;i<=y-1;i++){
				for(int j=i+1;j<=y;j++){
					ans=max(ans,s[i]&s[j]);
				}
			}
			cout<<ans;
			return 0;
		}
	}
	if(a[n]<=4){
		for(int i=1;i<=n;i++){
			if(a[i]==1) c1++;
			if(a[i]==2) c2++;
			if(a[i]==3) c3++;
			if(a[i]==4) c4++;	
		}
		if(c4>=m){
			cout<<4;
			return 0;	
		} 
		if(c3>=m){
			cout<<3;
			return 0;
		}
		if(c2+c3>=m){
			cout<<2;
			return 0;
		}
		if(c1+c3>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	return 0;
}
