#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
int n,m;
bool vis[200005];
unsigned long long mi2[50];
int main(){
	//666 zhe ti tai jian dan le , bi t2 hai jian dan , bi qu nian de t3 hai jian dan , nb666 , sysl .
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mi2[0]=1;
	for(int i=1;i<=31;i++){
		mi2[i]=mi2[i-1]*2;
	} 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	unsigned long long sum=0;
	for(int x=30;x>=0;x--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]%mi2[x+1]/mi2[x]) cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(a[i]%mi2[x+1]/mi2[x]) continue;
				vis[i]=1;
			}
			sum+=mi2[x];
		}
	}
	cout<<sum;
	return 0;
} 
