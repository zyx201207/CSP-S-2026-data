#include<iostream>
#include<map>
using namespace std;
int n,m;
map<int,int> mp;
map<int,int> cnt;
int a[500005];
void calc(int q){
	mp.clear();
	for(int i=q;i<=n;i++){
		if(mp[a[i]]==0) mp[a[i]]=i;
		else{
			for(int j=mp[a[i]]+1;j<i;j++){
				if(mp[a[j]]<i) mp[a[j]]=0;
			}
			mp[a[i]]=i;
		}
	}
	for(auto i=mp.begin();i!=mp.end();i++){
		if(i->second!=0){
			
			cnt[i->first]++;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			calc(i);
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
	}
	
	return 0;
}
