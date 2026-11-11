#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
const int N=2e5+10;
vector<int> bi[40];
int n,a[N],cnt[40],ans,t[N],flag,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				bi[j].push_back(i);
				cnt[j]++;
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			if(!flag){
				for(int j=0;j<bi[i].size();j++){
					t[bi[i][j]]++;
				}
				flag++;
				ans=ans|(1<<i);
			}
			else{
				int cn=0;
				for(int j=0;j<bi[i].size();j++){
					if(t[bi[i][j]]==flag){
						cn++;
					}
				}
				if(cn>=m){
					ans=ans|(1<<i);
					for(int j=0;j<bi[i].size();j++){
						t[bi[i][j]]++;
					}
				} 
				flag++;
			}
		}
	}
	cout<<ans;
	return 0;
}
