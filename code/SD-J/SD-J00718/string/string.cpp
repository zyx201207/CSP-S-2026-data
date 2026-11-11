#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int r=n;
	int cnt=a[n];
	long long ans=0;
	for(int i=1;i<=r;i++){
		while(a[i]>=cnt){
			if(i==r)break;
			if(c[i]!=c[r])ans+=cnt;
			a[i]-=cnt;
			r--;
			cnt=a[r];
		}
		if(i==r){
			break;
		}
		if(a[i]){
			if(c[i]!=c[r])ans+=a[i];
			cnt-=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
//Trick||Treat!
