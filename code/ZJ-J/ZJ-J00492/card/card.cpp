#include<bits/stdc++.h>
using namespace std;
int n,m,w;
int a[500010],cnt[300010];
long long sum[300010];
int book[500010];
map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			cnt[i]++;
		}
		for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+cnt[i];
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
		exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cerr<<cnt[j]<<" ";
		}
		cerr<"\n";
		cerr<<!mp.count(a[i])<<"\n\n";
		if(!mp.count(a[i])){
			++w;
			mp[a[i]]=w;
			book[w]=1;
		}
		else{
			if(book[mp[a[i]]]!=-1){
				for(int j=mp[a[i]];j<=w;j++){
					book[j]=-1;
				}
				w-=mp[a[i]];	
			}
			++w;
			mp[a[i]]=w;
			book[w]=1;
		}
		for(int j=1;j<=m;j++){
			if(book[mp[j]]==1&&mp.count(j)==1) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
