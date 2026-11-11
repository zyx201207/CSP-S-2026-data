#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],p,cnt[M],ans[M];
bitset<M>vis;
vector<int>v;
void Clear(){
	vector<int>tv;
	swap(tv,v);
}
void baolimoni(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			vis[j]=0;
		}
		Clear();
		p=0;
		for(int j=i;j<=n;j++){	
			if(vis[a[j]]==0){
				v.push_back(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(*(v.end()-1)!=a[j]){
					vis[*(v.end()-1)]=0; 
					v.pop_back();
				}
			}
		}
		for(int&j:v){
			ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
void m2(){
	int sum=0;
	for(int i=1;i<n;i++){
		if(a[i]!=a[n]){
			sum++;
		}
	}
	if(a[n]==1){
		cout<<n<<' '<<sum;
	}
	else{
		cout<<sum<<' '<<n;
	}
}
bool checkA(){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			return false;
		}
	}
	return true;
}
void teshuA(){
	int st=1;
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		m2();
		return 0;
	}
	if(checkA()){
		teshuA();
		return 0;
	}
	baolimoni();
	return 0;
}