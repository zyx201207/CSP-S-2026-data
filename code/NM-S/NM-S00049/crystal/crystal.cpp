#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,m,a[N],s[N],sum[N];
int find(int x,int y){
	int r;
	int sum=0;
	for(int i=0;i<n;i++){
		s[i]=a[i];
	}
	for(int i=0;i<n;i++){
		r=a[x]-s[i];
		if(r>=0){
			y-=r;
			if(y>=0){
				s[i]=a[x];
			}
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==a[x]){
			sum++;
		}
	}
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int _m=m;
	if(n==1){
		cout<<1;
		exit(0);
	}	
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	for(int i=0;i<n;i++){
		m=_m;
		sum[i]+=find(i,m);
	}
	int MAX_ans=-INT_MAX;
	for(int i=0;i<n;i++){
		MAX_ans=max(MAX_ans,sum[i]);
	}
	cout<<MAX_ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
