#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+5,MAX=pow(2,31)-1;
int a[N];
int n,m;
int ans=0;
clock_t st=clock();
void dfs(int depth,int v,int num){
	if(double(clock()-st)/CLOCKS_PER_SEC>0.85) return;
	if(num==m){
		ans=max(ans,v);
		return;
	}
	if(depth>n) return;
	dfs(depth+1,v&a[depth],num+1);
	dfs(depth+1,v,num);
}
unordered_map<int,bool> mp;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    string xz="11";
    for(int i=1;i<=31;i++) mp[pow(2,i)-1]=1;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1&&a[i-1]+1!=a[i]) xz[1]='0';
		if(!mp[a[i]]) xz[0]='0';
	}
	if(xz[0]=='1'||xz[1]=='1'){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		//cerr<<"xz"<<xz;
    }else{
		sort(a+1,a+n+1,greater<int>());
		dfs(1,MAX,0);
		cout<<ans;
	}
	//cout<<endl;
	// end=clock();
	//double sec=double(end-st)/CLOCKS_PER_SEC;
	//if(sec>=1) cerr<<"TLE "<<sec<<endl;
	//else cerr<<"AC"<<endl;
    return 0;
}
