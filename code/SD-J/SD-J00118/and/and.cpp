#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;

int n,m;
int ans=-1;
int a[MAXN];
bool vis[MAXN];

int search(int pos){
	int cnt=0;
	int sum=a[pos];
	int t=a[pos];
	vis[pos]=1;
	
	while(cnt<m){
		int maxn=-1;
		for(int j=pos+1;j<=n;j++){
			
			if(!vis[j]&&(t&a[j])>maxn){
				maxn=a[j];
				t&=a[j];
				vis[j]=1;
				++cnt;
			}
		}
		sum&=maxn;
	}
	return sum;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//A
	int flag=0;
	int spe=-1;
	for(int i=1;i<=n;i++){
		if((a[i]+1)%2!=0)
			flag=1;
	}
	if(!flag){
		for(int i=1;i<=n;i++)
			spe=max(a[i],spe);
		cout<<spe<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,search(i));
	
	cout<<ans<<endl;
	
	return 0;
}
