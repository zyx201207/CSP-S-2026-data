//考号：SN-J00760  姓名：刘浩宇  学校：西安市汇知中学 
#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false);
using namespace std;
int n,m,a[200005],ans,maxn,h;
string s[200005];
int fang(int a,int b){
	int h=1;
	for(int i=1;i<=b;i++){
		h*=a;
	}
	return h;
}
signed main(){
	IOS
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int u=a[i];
		while(u){
			s[i]+=u%2;
			u/=2;
		}
		int c=s[i].size()-1;
		maxn=max(maxn,c);
	}
	for(int i=maxn;i>=0;i--){
		h=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=0&&s[j].size()>i){
				if(s[j][i]==1){
					h++;
				}
			}
		}
		if(h>=m){
			for(int j=1;j<=n;j++){
				if(s[j][i]==0){
					a[j]=-1;
				}
			}
			ans+=fang(2,i);
		}
	}
	cout<<ans;
	return 0;
}
