#include<bits/stdc++.h>
using namespace std;
vector<int> des;
int a[300010],cnt[300010];
int n,m;
int z[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		des.clear();
		for(int j=i;j<=n;j++){
			if(z[a[j]]!=i){
				des.push_back(a[j]);
				z[a[j]]=i;
			}
			else{
				int pos=find(des.begin(),des.end(),a[j])-des.begin();
				des.erase(des.begin()+pos,des.begin()+des.size());
				des.push_back(a[j]);
			}
		}
		for(auto it=des.begin();it!=des.end();it++){
			cnt[*it]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
