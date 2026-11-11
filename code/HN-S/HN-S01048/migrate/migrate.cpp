#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long c,t,n,d,a[N],ans,sum,h;
vector <long long> v;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				sum=1e9;
				h=0;
				for(int k=0;k<(1<<j-i-1);k++){
					v.clear();
					v.push_back(i);
					for(int l=0;l<j-i-1;l++){
						if((k>>l)&1){
							v.push_back(i+l+1);
						}
					}
					v.push_back(j);
					bool flag=1;
					for(int l=1;l<v.size();l++){
						if(a[v[l]]-a[v[l-1]]>d){
							flag=0;
							break;
						}
					}
					if(flag){
						if(v.size()-1==sum){
							h++;
						}
						else if(v.size()-1<sum){
							sum=v.size()-1;
							h=1;
						}
					}
				}
				if(h==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
