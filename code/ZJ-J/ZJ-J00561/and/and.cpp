#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,f[30],x[30][30],cnt[30],mn1=INT_MAX;
bool flag1=1;
vector<int> ans;
void find(int a){
	int f1=0;
	for(int i=29;i>=0;i--){
		if(a==pow(2,i)-1){
			f1=1;
			mn1=min(mn1,i-1);
			break;
		}
	}
	flag1&=f1;
	memset(f,0,sizeof(f));
	for(int i=29;i>=0;i--){
		if(a>=pow(2,i)){
			a-=pow(2,i);
			cnt[i]++;
			f[i]=1;
		}
	}
	for(int i=29;i>=0;i--)for(int j=29;j>=0;j--)if(f[i]&&f[j]){x[i][j]++;x[j][i]++;}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		long long a[N],mx=INT_MIN;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<1<<n;i++){
			vector<int>g;
			long long ns=-1;
			for(int j=0;j<n;j++){
				if(i>>j&1){
					g.push_back(a[j]);
					if(ns==-1)ns=a[j];
				}
			}
			if(g.size()!=m)continue;
			for(int v:g){
				ns&=v;
			}
			mx=max(mx,ns);
		}
		cout<<mx;
		return 0;
	}
	int a;
	bool flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=i-1){
			flag2=0;
		}
		find(a);
	}
	if(flag2){
		long long ns=0;
		int k=-1,vp=0;
		for(int i=29;i>=1;i--){
			if(m<=pow(2,i)&&m>=pow(2,i-1)&&k!=-1){
				k=i;
			}
			if(n==pow(2,i))vp=i;
		}
		for(int i=vp;i>=vp-k;i--){
			ns+=pow(2,i);
		}
		cout<<ns;
		return 0;
	}
	if(flag1){
		long long ns=0;
		for(int i=0;i<=mn1;i++){
			ns+=pow(2,i);
		}
		cout<<ns;
		return 0;
	}
	int mx=-1;
	for(int i=29;i>=0;i--){
		if(f[i]>=m){
			mx=i;
			ans.push_back(i);
			break;
		}
	}
	if(mx==0){
		cout<<1;
		return 0;
	}
	if(mx==-1){
		cout<<0;
		return 0;
	}
	m=n;
	for(int i=mx;i>=0;i--){
		bool f=1;
		int mnn=INT_MAX;
		for(int v:ans){
			if(x[v][i]>=m){
				mnn=min(x[v][i],mnn);
			}else{
				f=0;
				break;
			}
		}
		if(f){
			m=min(m,mnn);
			ans.push_back(i);
		}
	}
	long long ns=0;
	for(int v:ans){
		ns+=pow(2,v);
	}
	cout<<ns;
	return 0;
}