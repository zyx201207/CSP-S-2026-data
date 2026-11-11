#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const int M=3e5+7;
int n,m;
int a[N];
int cnt[M];
int ans[M];
vector<int> res,temp;
int s[M];
bool f=true;
void solve3(){
	for(int i=1;i<=n;i++){
		cnt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		s[a[i]]=cnt[a[i]];
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=false;
		}
	}
	if(m==1){
		cout<<n<<'\n';
	}
	else if(f){
		solve3();
	}
	else{
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				if(cnt[a[i]]!=0){
					for(int k:res) cnt[k]=0;
					res.clear();
					cnt[a[i]]=1;
					res.push_back(a[i]);
				}
				else{
					cnt[a[i]]++;
					res.push_back(a[i]);
				}
			}
			for(int k:res){
				ans[k]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
