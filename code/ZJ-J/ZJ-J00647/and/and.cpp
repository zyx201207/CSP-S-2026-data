#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010];
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=29;i>=0;--i){
		int c=0;
		for(int j=0;j<n;++j){
			if(a[j]>=0 && ((1<<i) & a[j]))++c;
		}
		if(c==m){
			int ans=0x3fffffff;
			for(int j=0;j<n;++j){
				if(a[j]>=0 && ((1<<i) & a[j]))ans&=a[j];
			}
			cout<<ans;
			return 0;
		}
		if(c>m){
			for(int j=0;j<n;++j){
				if(a[j]>=0 && !((1<<i) & a[j]))a[j]=-1;
			}
		}
	}
	sort(a,a+n,cmp);
	int ans=0x3fffffff;
	for(int i=0;i<m;++i){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}