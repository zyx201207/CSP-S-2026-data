#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//x&y  =   x%(y+1) 
int n,m;
int v[N];
long long a[N],ans;
void pig(int cnt,long long sum){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	long long x;
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			x=sum&a[i];
			pig(cnt+1,x);
			v[i]=0;
		}
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i-1){
			f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
		pig(1,a[i]);
		v[i]=0;
	}
	cout<<ans;
	return 0;
} 

