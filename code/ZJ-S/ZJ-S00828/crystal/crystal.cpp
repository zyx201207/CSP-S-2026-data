#include<bits/stdc++.h>
using namespace std;
const int inf=500005;
struct node{
	long long i,c;
};
node d[inf];
long long n,m;
int a[inf];
long long ans=0;
bool cmp(node x,node y){
	return x.c<y.c;
}
int dfs(long long x){
	long long c=m;
	long long t=x+1;
	long long ans=1;
	int j=0;
	while(c>=0){
		for(int k=x;k<t;k++){
			j++;
			for(int i=0;i<j;i++){
				c-=d[k].c;
			}
		}	
		ans++;
		t++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i].i=i;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i].c=a[i]-a[i-1];
	}
	int x=d[2].c;
	int f=0;
	for(int i=3;i<=n;i++){
		if(d[i].c!=x){
			f=1;
		}
	}
	if(f==0){
		int y=1;
		while(m>=0){
			m-=y*x;
			ans++;
			y++;
		}
	}else{
		sort(d+2,d+1+n,cmp);
		for(int i=2;i<=n;i++){
			if(ans<dfs(d[i].i))
				ans=dfs(d[i].i);
		}
	}
	cout<<ans;
	return 0;
}