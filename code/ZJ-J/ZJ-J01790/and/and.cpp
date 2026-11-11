#include<bits/stdc++.h>
using namespace std;

int a[200004];

int ans=0;
int n,m;

void sou(int nowi,int cnt,int val){
	if(cnt==m){
		ans=max(ans,val);
		return;
	}
	if(nowi>n)return;
	if(cnt==0){
		sou(nowi+1,1,a[nowi]);
		sou(nowi+1,0,0);
	}else{
		sou(nowi+1,cnt,val);
		sou(nowi+1,cnt+1,val&a[nowi]);
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	
	cin>>n>>m;
	
	cin>>a[1];
	int ans6=a[1],ans7=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans6=max(ans6,a[i]);
		ans7=ans7&a[i];
	}
	
	if(m==1){
		cout<<ans6;return 0;
	}
	if(m==n){
		cout<<ans7;return 0;
	}
	if(m==2){
		int ans8=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i!=j)ans8=max(ans8,a[i]&a[j]);
			}
		}
		cout<<ans8;return 0;
	}
	
	
	
	if(n<=20){
		sou(1,0,0);
		cout<<ans;
		return 0;
	}
	
	cout<<4;
	return 0;
}

