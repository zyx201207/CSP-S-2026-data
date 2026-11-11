#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

int pok[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pok[i];
	}
	int ans[500010];
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		vector<int> now(0);
		for(int j=i;j<=n;j++){
			bool f=false;
			for(int k=0;k<now.size();k++){
				if(now[k]==pok[j]){
					f=true;
					while(now.size()>k){
						now.pop_back();
					}
				}
			}
			now.push_back(pok[j]);
		}
		for(int k=0;k<now.size();k++){
			ans[now[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
