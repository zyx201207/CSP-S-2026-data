#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int t[N];
int color[M];
int tail[M];
int a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	while(x<=n){
		int p=-1,mn;
		for(int i=n;i>=x;i--){
			if(t[a[i]]!=0){
				p=i;
				mn=t[a[i]];
				break;
			}
			t[a[i]]=i;
			tail[a[i]]++;
		}
		for(int i=n;i>=x;i--){
			t[a[i]]=0;
		}
		if(p!=-1){
			for(int i=1;i<=m;i++){
				tail[i]=0;
			}
			for(int i=n;i>=mn;i--){
				tail[a[i]]++;
			}
			for(int i=1;i<=m;i++){
				color[i]+=tail[i]*p;
				tail[i]=0;
			}
		}
		else{
			for(int i=n;i>=x;i--){
				color[a[i]]+=(i-x+1);
			}
			break;
		}
		x=p+1;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",color[i]);
	}
	return 0;
} 






























