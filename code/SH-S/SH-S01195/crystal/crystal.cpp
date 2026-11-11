#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],xmi=0,xma=0;
int n,l=1,r=1,ans=0,anss=0;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	xmi=a[1];
	while(m){
		if(r>=n) break;
		int cnt=a[r+1]-a[r];
		cnt*=(r-l+1);
		if(m-cnt<0){
			break;
		}
		r++;
		m-=cnt;
		xma=a[r];
	}
	ans=r-l+1;
	anss=max(anss,ans);
	for(;r<n;){
		int count=xma-a[l];
		m+=count;
		ans--;
		l++;
		while(m){
			if(r>=n) break;
			int cnt=a[r+1]-a[r];
			cnt*=(r-l+1);
			if(m-cnt<0){
				break;
			}
			r++;
			m-=cnt;
			xma=a[r];
		}
		ans=r-l+1;
		anss=max(anss,ans);
	}
	cout<<anss;
	return 0;
}
