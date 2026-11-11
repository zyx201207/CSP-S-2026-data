#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7;
int a[maxn],id[maxn],m,sum;
int n;
int f(int x,int idx){
	priority_queue<int,vector<int>,greater<int> >op;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(a[i]>idx){
			continue;
		}
		op.push(idx-a[i]);
	}
	while(x>0){
		int y=op.top();
		if(x-y>=0){
			x-=y;
			cnt++;
		}else{
			break;
		}
		op.pop();
		if(op.size()==0){
			break;
		}
	}
	return cnt;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		sum+=a[i];
		k=a[i]-a[i-1];
	}
	//B
	bool flagB=0,flagA=0;
	for(int i=1;i<n;++i){
		if(a[i+1]-a[i]!=k){
			flagB=1;
		}
	}
	//A
	for(int i=1;i<=n;++i){
		if(a[i]!=i){
			flagA=1;
		}
	}
	double xx=sum/double(n),minn=1e8;
	for(int i=1;i<=n;++i){
		if(minn>abs(xx-a[i])){
			minn=abs(xx-a[i]);
			id[1]=a[i];
		}
		if(minn==abs(xx-a[i])&&id[1]!=a[i]&&id[2]!=a[i]){
			id[2]=a[i];
		}
	}
	
	if(flagA==0||flagB==0){
		if(id[2]!=0){
			cout<<max(f(m,id[1]),f(m,id[2]));
		}else{
			cout<<f(m,id[1]);
		}
		return 0;
	}
	
	int w=1;
	for(int i=1;i<=n;++i){
		if(a[i]>id[1]){
			id[++w]=a[i];
		}
	}
	int cnt=0;
	for(int i=1;i<=w;++i){
		if(id[i]==0) continue;
		cnt=max(cnt,f(m,id[i]));
	}
	cout<<cnt;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
6 10 
1 2 3 4 5 6
6 10 
4 6 8 10 12 14
6 9999
1 1 1 1 1 5
6 9999
1 1 1 5 5 5
*/
