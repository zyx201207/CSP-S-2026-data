#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],b[maxn],c[maxn],cnt[maxn];
int n,m;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c,c+n);
	int ans=0;
	int ans_1=0;
	bool fl=0;
	for(int i=0;i<n;i++){
		if(c[i]==c[i+1]){
			if(i>1 && c[i]!=c[i-1] && c[i-1]==c[i-2]){
				ans_1--;
			}
			ans_1++;
		}
	}
	if(m>=ans_1){
		for(int i=0;i<n;i++){
			if(c[i]==c[i+1]){
				ans++;
			}
		}
	}
	ans--;
	for(int i=0;i<n;i++){
		b[i]=abs(c[i]-c[i+1]);
	}
	long long minx=1e12+10;
	int minx_i;
	b[n]=abs(c[n-1]-c[0]);
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(b[i]>minx && c[i]!=c[i+1]){
				minx=b[i];
				minx_i=i;
			}
		}
		if(c[minx_i]>c[minx_i+1]){
			c[minx_i+1]++;
			b[minx_i]--;
			if(c[minx_i+1]>=c[minx_i+2]){
				b[minx_i+1]++;
			}else{
				b[minx_i+1]--;
			}
		}else{
			c[minx_i]++;
			b[minx_i]--;
			if(c[minx_i]>=c[minx_i-1]){
				b[minx_i-1]++;
			}else{
				b[minx_i-1]--;
			}
		}
	}
	int maxx=-1;
	for(int i=0;i<n;i++){
		cnt[c[i]]++;
	}
	for(int i=0;i<n;i++){
		maxx=max(maxx,cnt[c[i]]);
	}
	if(ans==-1) ans++;
	int anss=maxx+ans;
	if(anss>=n){
		anss-=ans;
	}
	if(ans>1){
		anss++;
	}
	cout<<anss;
	return 0;
}

