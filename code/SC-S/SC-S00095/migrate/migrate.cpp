#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T;
int n;
long long d,a[N];
int dp1[5005],dp2[5005];
multiset<int> st;
map<int,int> mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=10){
			for(int i=1;i<=n;i++){
				dp1[i]=0;
				dp2[i]=1;
				int s=i;
				st.clear();
				mp.clear();
				st.insert(0);
				mp[0]=1;
				for(int j=i+1;j<=n;j++){
					dp1[j]=2e9;
					while(a[s]<a[j]-d){
						if(dp1[s]!=2e9){
							st.erase(st.find(dp1[s]));
							mp[dp1[s]]-=dp2[s];
						}
						s++;
					}
					if(st.size()){
						dp1[j]=(*st.begin())+1;
						dp2[j]=mp[*st.begin()];
						st.insert(dp1[j]);
						mp[dp1[j]]+=dp2[j];
						if(dp2[j]==2){
							ans++;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}