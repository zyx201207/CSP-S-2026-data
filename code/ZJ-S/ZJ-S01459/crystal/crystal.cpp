#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int pre[N];
int b[N];
bool flag=1;
void solve(){
	int ans=1;
	if(n%2==1){
		int p=n/2+1;
		int l=p-1;
		int r=p+1;
		while(l>=1||r<=n){
			int left=p-l;
			int right=r-p;
			if(l==0) left=1e18;
			if(r==n+1) right=1e18; 
			if(left<right){
				if(left<=m){
					m-=left;
					l--;
				//	continue;
				}else break;
			}else{
				if(right<=m){
					m-=right;
					r++;
					//continue;
				}else break;
			}
			ans++;
		}
		cout<<ans<<"\n";
	}else{
		int p=n/2;
		int q=n/2+1;
		if(m==0){
			cout<<ans<<"\n";
			return ;
		}
		int l=p-1;
		int r=q+1;
		m--;
		ans++;
		//cout<<m<<"\n";
		while(l>=1||r<=n){
			int left=p-l;
			int right=r-p;
			//cout<<left<<" "<<right<<" "<<m<<"\n";
			if(l==0) left=1e18;
			if(r==n+1) right=1e18; 
			if(left<right){
				if(left<=m){
					m-=left;
					l--;
				//	continue;
				}else break;
			}else{
				if(right<=m){
					m-=right;
					r++;
				//	continue;
				}else break;
			}
			ans++;
			//cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
}
int mx=1;
void dfs(int x,int a[]){
	if(x==0){
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			mp[a[i]]++;
		}
		for(auto i:mp){
			mx=max(mx,i.second);
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		a[i]+=1;
		dfs(x-1,a);
		a[i]--;
	}
}
signed main(){
   // freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//pre[i]=pre[i-1]+a[i];
		if(a[i]!=i){
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	if(flag){
		solve();
	//	cout<<1<<"\n";
		return 0;
	}
	if(n<=5&&m<=10){
		dfs(m,a);
		cout<<mx<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(b+1,b+n+1);
	int right=1;
	int ans=1;
	int e=0;
	//cout<<"1\n";
	for(int i=1;i<=n;i++){
		int l=1,r=i,pos=i;
		int c=b[i]*(i-right);
	//	cout<<c<<"\n";
		if(c+e<=m){
			//cout<<i<<" "<<right<<"\n";
			ans=max(ans,i-right+1);
			e=c;
		//	right++;
		}else{
		//	cout<<c<<"\n";
			right++;
		//	e=c-b[right-1];
			e=min(e,b[i]);
			//e=0;
		}
		//e=c;
	}
	cout<<ans<<"\n";
	return 0;
}// my grade is so bad; the highest grade is 50 ,the badest is 29;
