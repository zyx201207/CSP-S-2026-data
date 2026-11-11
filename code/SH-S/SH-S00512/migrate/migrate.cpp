#include<bits/stdc++.h>
using namespace std;
bool fff,fff2;
long long c,t,n,d,ans,c1,c2;
long long x[2100000];
vector<pair<long long,long long> > ttt;
long long flag[2100000],flag2[2100000];
pair<long long,long long> far[2100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (long long nouse=1;nouse<=t;nouse++){
		memset(flag,0,sizeof(flag));
		memset(flag2,0,sizeof(flag2));
		ttt.clear();
		c1=c2=0;
		ans=0;
		fff=false;
		fff2=false;
		cin>>n>>d; 
		for (long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for (long long i=1;i<=n&&x[i]-x[1]<=d;i++){
			far[1].second=i;
		}
		far[far[1].second].first=1;
		long long l=1,r=far[1].second;
		while(r<=n){
			l++;
			while(x[r+1]-x[l]<=d&&r+1<=n){
				r++;
			}
			if (l!=r){
				far[l].second=r;
				far[r].first=l;
			}
			if (r==n){
				break;
			}
		}
		for (long long i=1;i<=n;i++){
			if (far[i].second){
				if (far[far[i].second-1].second&&far[i].second!=far[far[i].second-1].second&&i!=far[i].second-1){
					flag[i]=flag[far[far[i].second-1].second]=1;
					ttt.push_back(make_pair(i,far[far[i].second-1].second));
				}
			}
		}
		for (long long i=1;i<=n-1;i++){
			if (x[i+1]-x[i]>d){
				flag2[i]=-1;
				flag2[i+1]=-1;
			}
		}
		for (auto i:ttt){
			c1=c2=0;
			fff=false;
			fff2=false;
			for (long long j=i.first+1;j<=i.second-1;j++){
				if (flag[j]==1){
					fff=true;
				}
			}
			for (long long j=i.first;j>=1;j--){
				if (flag2[j]==-1){
					if (fff2){
						break;
					}
					else{
						fff2=true;
					}
				}
				if (flag[j]==1&&j!=i.first){
					if (fff){
						break;
					}
					else{
						fff=true;
					}
				}
				c1++;
			}
			fff=false;
			fff2=false;
			for (long long j=i.first+1;j<=i.second-1;j++){
				if (flag[j]==1){
					fff=true;
				}
			}
			for (long long j=i.second;j<=n;j++){
				if (flag2[j]==-1){
					if (fff2){
						break;
					}
					else{
						fff2=true;
					}
				}
				if (flag[j]==1&&j!=i.second){
					if (fff){
						break;
					}
					else{
						fff=true;
					}
				}
				c2++;
			}
			ans+=c1*c2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
