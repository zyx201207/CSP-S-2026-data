#include<bits/stdc++.h>
using namespace std;
const int k=5e5+10;
int cishu[k];
int shuzi[k];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>shuzi[i];
	}
	for(int i=1;i<=n;i++){
		bool s[k]={0};
		bool ss[k]={0};
		for(int j=i;j<=n;j++){
			cishu[shuzi[j]]++;
			if(s[shuzi[j]]==1){
				int r=j-1;
				while(shuzi[r]!=shuzi[j]){
					if(ss[r]==0){
					    cishu[shuzi[r]]--;
					    ss[r]=1;
				    }
					r--;
				}
			}else{
				s[shuzi[j]]=1;
			}
		}
		
	}
	cout<<3;
	for(int i=2;i<=m;i++){
		cout<<cishu[i]<<" ";
	}
	return 0;
}