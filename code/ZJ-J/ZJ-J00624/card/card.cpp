#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500010];
map<int,int> mp;
int cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		mp.clear();
		for(int i=k;i<=n;i++){
			if(!mp[a[i]]){
				mp[a[i]]=i;
			}
			else{
				for(int j=mp[a[i]];j<=i;j++){
					mp[a[j]]=0;
				}
				mp[a[i]]=i;
			}
		}
		for(auto t:mp){
			if(t.second!=0){
				cnt[t.first]++;
			}
//			cout<<k<<" "<<t.first<<" "<<t.second<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
// bro, why running error??? my 24 pts!!!
