#include<algorithm>
#include<cmath>
#include<string>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
int n,m,maxx=-1,maxa=-1,p,maxp=-1,ans=0,flagA=0,FlagA=0;
int a[200005];
int b[35];
void dfs(int sum,int i,int step){
	if(step==m){
		maxa=max(maxa,sum);
		return;
	}
	else{
		for(int j=i-1;j>=0;j--){
			if(sum&a[j]<maxa) continue;
			dfs(sum&a[j],j,step+1);
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		p=0,FlagA=0;
		for(int t=1;t<=a[i];t*=2){
			if(a[i]==0) break;
			if(a[i]&t){
				b[p]++;
				FlagA++;
			}
			maxp=max(maxp,p);
			p++;
		}
		if(FlagA!=p) flagA=1;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(!flagA){
		cout<<a[m];
		return 0;
	}
	if(b[2]>=m&&maxp==2){
		cout<<4;
		return 0;	
	}
	if(b[2]<m&&maxp==3){
		int sum33333=0,sum22222=0,sum11111=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) sum11111++;
			else if(a[i]==2) sum22222++;
			else sum33333++;
			if(sum33333>=m){
				cout<<3;
				return 0;
			}
			else if(sum33333+sum22222>=m){
				cout<<2;
				return 0;
			}
			else if(sum33333+sum11111>=m){
				cout<<1;
				return 0;
			}
			else {
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=n;i>=m;i--){
		dfs(a[i],i,1);
	}
	cout<<maxa;
	return 0;
}
