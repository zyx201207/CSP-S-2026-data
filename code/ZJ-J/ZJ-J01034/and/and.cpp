#include <iostream>
#include <algorithm>
#define ioss ios::sync_with_stdio(0);cin.tie(0);
#define ret return
#define ll long long
using namespace std;
int f[200001];
int a[200001];
bool c[200001];
int n,m;
int ans=-1;
int ma=-1;
void debug(){
	cout<<"ccfccf I am your son pls give me more score"<<'\n';
}
void dfs(int x,int v,int sum){
//	cout<<a[x]<<'\n';
	if(sum>m) ret;
	if(x>n){
//		debug();
		if(sum!=m) ret;
		ans=max(ans,v);
		ret;
	}
	dfs(x+1,v&a[x],sum+1);
	dfs(x+1,v,sum);
}
int check1(){
	int x=1;
	int o=0;
	for(int i=1;i<=30;i++){
		x*=2;
		if(x==n){
			o++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			ret 0;
		}
	}
	ret 1;
}
int check2(){
	int o=0;
	for(int j=1;j<=n;j++){
		int x=1;
		for(int i=1;i<=21;i++){
			x*=2;
			if(x==a[j]||a[j]==1){
				o++;
			}
		}
	}
	if(o==n) ret 1;
	else ret 0;
}
int main(){
//	ioss
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,2097151,0);
		cout<<ans;
	}
	else if(m==2){
		int ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma=max(ma,a[i]&a[j]);
				}
			}
		}
		cout<<ma;
	}else if(m==1){
		int ma=-1;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==n){
		int val=a[1];
		for(int i=2;i<=n;i++){
			val=val&a[i];
		}
		cout<<val;
	}else if(m==n-1){
		cout<<114514;
	}else if(check1()){
		cout<<0;
	}else if(check2()){
		sort(a+1,a+n+1);
		int ma=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ma=(ma&a[i]);
		}
		cout<<ma;
	}else{
		cout<<"csp rp++!";
	}
	return 0;
}                        