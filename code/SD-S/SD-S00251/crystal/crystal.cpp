#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
bool cmp(int a,int b){
	return a<b;
}
int s[N];
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1){
		cout<<1<<endl;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	int l=1;//区间最左 
	int len=1;// 区间长度 
	for(int i=2;i<=n;i++){//i指向最右 
		len++; 
		while(len*a[i]>s[i]-s[l-1]+m){
			l++;
			len--;
		}
		ans=max(ans,len);
	}
	cout<<ans<<endl; 
	return 0;
} 
