#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,s=1,e=2;
pair<int,int>b[5000][5000];
vector <int> a;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		a.clear();
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		if((c==11||c==12)&&n>=4){
			//cout<<n<<" "<<d<<" "<<a[2]-a[1]<<" ";
			if(a[3]-a[1]<=d){
				int anss=n-((int)(d/(a[2]-a[1]))*2-1);
				if(anss>0){
					cout<<anss<<endl;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<endl;
			}
		}
		else if(c==13||c==14){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i-1]-a[0]<d&&a[n-1]-a[i-1]<d){
					cnt++;
				}
			}
			if(cnt==2){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i-1]-a[j-1]<=d){
						b[i][j]={1,1};
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=i;j<=n;j++){
						if(b[i][k].first!=0&&b[k][j].first!=0){
							b[i][j].second+=1;
						}
					}
				}
			}
			int anss=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(b[i][j].second==2){
						anss++;
					}
				}
			}
			cout<<anss<<endl;
		}
	}
	return 0;
}