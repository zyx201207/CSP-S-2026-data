#include<bits/stdc++.h>
using namespace std;
long long m,n,v[200010],a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=0;
	}
	for(int i=29;i>=0;i--){
		int s=0;
		int maxn=pow(2,i);
		for(int j=1;j<=n;j++){
			if(a[j]>=maxn)s++;
		}
		if(s>=m){
			for(int j=1;j<=n;j++){
				if(a[j]>=maxn)v[j]+=maxn;
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]>=maxn)a[j]-=maxn;
		}
	}
	sort(v+1,v+n+1,greater<int>());
	int maxn=v[1];
	
	int s=0;
	for(int i=1;i<=n;i++){
		
		if(v[i]>=maxn)s++;
		else {
			maxn=v[i];
			s++;
		}
		if(s>=m)break;
	}
	cout<<maxn;
	return 0;
}

