#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],r,ran;
ll p2[50];
bool b[N][40];
vector<ll>ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;p2[0]=1;
	for(int i=1;i<=n;i++)p2[i]=p2[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],cnt=0;
		while(x){
			if(x&1)b[i][cnt]=1;
			x>>=1;
			cnt++;
		}
	}for(int i=33;i>=0;i--){
		int cnt=0;
		vector<ll>v;
		for(int j=1;j<=n;j++){
			if(b[j][i]){
				cnt++;
				v.push_back(j);
			}
		}if(cnt>=m){
			r=i;int vs=v.size();
			for(int j=0;j<vs;j++){
				ans.push_back(v[j]);
				
			}
			break;
		}
	}for(int i=r-1;i>=0;i--){
		int cnt=0;
		vector<ll>v;ll anss=ans.size();
		for(int j=0;j<anss;j++){
			if(b[ans[j]][i]){
				cnt++;
				v.push_back(ans[j]);
			}
		}if(cnt>=m){
			ans.clear();int vs=v.size();
			for(int j=0;j<vs;j++){
				ans.push_back(v[j]);
			//	cout<<v[j]<<"\n";
			}ran+=p2[i];
		}
	}cout<<ran+p2[r];
	
	return 0;
} 
