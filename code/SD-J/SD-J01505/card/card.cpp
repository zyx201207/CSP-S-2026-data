#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int s[100005],cnt; 
bool vis[100005];
int f[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=m;j++){
			vis[j]=false;
			s[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				s[++cnt]=a[j];
				vis[a[j]]=true;
			}
			else {
				int flag;
				for(int x=1;x<=cnt;x++){
					if(s[x]==a[j]) flag=x;
				} 
				for(int x=flag;x<=cnt;x++){
					vis[s[x]]=false;
					s[x]=0;
				}
				cnt=flag-1;
				s[++cnt]=a[j];
				vis[a[j]]=true;
			}
		} 
		for(int j=1;j<=cnt;j++){
			f[s[j]]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
} 
