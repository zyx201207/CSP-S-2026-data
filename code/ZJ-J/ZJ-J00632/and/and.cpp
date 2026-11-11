#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],mx,v[200100],mz,b[200100],t[200100],f;
void dfs(long long h,long long sh){
	if(sh==m){
		mx=max(mx,h);
		return;
	}
	if(h==0)return;
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(h&a[i],sh+1);
			v[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		mz=max(mz,a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(mz<=4){
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[4]>=m)cout<<4;
		else if(t[3]>=m)cout<<3;
			else if(t[2]>=m)cout<<2;
				else if(t[3]+t[1]>=m)cout<<1;
					else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(b[i]>0){
			if(b[i]%2==1){
				f=1;
				break;
			}
		}
		if(f==1)break;
	}
	if(!f){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			v[i]=1;
			dfs(a[i],1);
			v[i]=0;
		}
		cout<<mx;
	}	
}

