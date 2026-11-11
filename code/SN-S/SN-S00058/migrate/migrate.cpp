#include<bits/stdc++.h>
using namespace std;
const int maxn = 5010;
int c,t;
int n;
long long d;
long long a[maxn];
bool vis[maxn];
long long ans;
vector<int> bk;
/*bool check2(int l,int r){
	for(int i=l;i<=r;i++){
		if(!vis[i]){
			return true;
		}
	}
	return false;
}*/
bool check(int l,int r){
	memset(vis,0,sizeof(vis));
	for(auto v:bk){
		if(v>=l && v<=r){
			return false;
		} 
	}
	long long cnt=0,anss=0;
	vis[l]=true;
	while(!vis[r]){
		for(int i=l;i<=r;i++){
			if(vis[i]){
				int head=i,tail=i;
				while(a[i]-a[head-1]<=d && head-1>=l){
					head--;
					if(head==r){
						anss++;
					}
					vis[head]=true;
				}
				while(a[tail+1]-a[i]<=d && tail+1<=r){
					tail++;
					if(tail==r){
						anss++;
					}
					vis[tail]=true;
				}
			}
		}
		cnt++;
	}
	return anss==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1){
				if(a[i]-a[i-1]>d){
					bk.push_back(i); 
				}
			}
		}
		//dou force le hai guan shen me fu za du
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(check(j,i)){
					ans++;
				} 
			}
		}
		//check --> judge the shuang
		//I open the o2,the kaochang has been in a loss of o2 for the whole time
		cout<<ans/3<<'\n';
	}
	return 0;
} 
