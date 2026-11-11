#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
map<int,int>mp;
int a[N],n,m,mx=INT_MIN;
bool cmp(int a,int b){
	return a>b;
}
int vis[50];
void dfs(int s,int sum,bool f){
	if(s==m){
		mx=max(mx,sum);return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(!f){
				sum=a[i];
				dfs(s+1,sum,1);
			}else{
				dfs(s+1,sum&a[i],1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f0=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>4)f0=0;
	}
	if(n<=20){
		dfs(0,0,0);cout<<mx;
	}else if(m==1||m==2||m==n){
		if(m==1){
			for(int i=0;i<n;i++){
				mx=max(mx,a[i]);
			}
			cout<<mx;
		}else if(m==2){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					mx=max(mx,a[i]&a[j]); 
				}
			}
			cout<<mx;
		}else if(m==n){
			mx=a[0]&a[0]; 
			for(int i=1;i<n;i++){
				mx=mx&a[i];
			}
			cout<<mx;
		}
	}else if(m==n-1){
		int mx=a[0]&a[0]; 
		for(int i=1;i<n;i++){
			mx=max(mx&a[i],mx);
		}
		cout<<mx;
	}else if(f0){
		for(int i=0;i<n;i++){
			mp[a[i]]++;
		} 
		if(mp[4]>=m){
			cout<<4;
		}else if(mp[3]>=m){
			cout<<3;
		}else if(mp[2]+mp[3]>=m){
			cout<<2;
		}else if(mp[1]+mp[3]>=m){
			cout<<1;
		}else cout<<0;
	}else{
		sort(a,a+n,cmp);
		cout<<a[m-1];
	}
	return 0;
}
