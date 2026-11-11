#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
/*####################*/
using lnt=long long;
const int N=2e5+10;
/*####################*/
bool weishu[N][35];
int t[N];
int __pow(int a,int b){
	int ans=1;for(int i=1;i<=b;i++) ans*=a;
	return ans;
}
/*####################*/
void Solve(void){
	int n,m;cin>>n>>m;
	int maxn=0,ans=0;
	vector<int> vec[32];
	for(int i=1;i<=n;i++){
		int op;cin>>op;
		vec[30].push_back(i); 
		for(int j=0;j<=31;j++){
			if(op==0) break;
			else{
				maxn=max(maxn,j);
				weishu[i][j]=(op%2);
				t[j]+=weishu[i][j];
				op/=2;
			}
		}
	}for(int i=maxn;i>=0;i--){
		if(t[i]<m){
			if(i!=0) 
				for(int j:vec[i]){
					vec[i-1].push_back(j);
				}
		}else{
			ans+=__pow(2,i);
			for(int j:vec[i]){
				if(i==0) break;
				if(weishu[j][i]) vec[i-1].push_back(j);
				else{
					for(int k=0;k<i;k++){
						t[k]-=weishu[j][k];
					}
				}
			}
		}
	}cout<<ans;
}
/*####################*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;//cin>>T;
	while(T--) Solve();
	return 0; 
}
