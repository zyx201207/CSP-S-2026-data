#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0;
long long a[100000],ans[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	/*for(int i=1;i<=n;i++) cin>>a[i];*/
	for(long long i=1;i<=n;i++) cin>>a[i];
	
	for(long long k=1;k<=n;k++){
		long long p[100000]={0};
		long long wei=0;
		for(long long i=k;i<=n;i++){
			long long w=a[i];
			bool biao=1; 
			for(int j=1;j<=wei;j++){
				if(p[j]==w){
					wei=j;
					biao=0;
					break;
				}
			} 
			if(biao){
				p[wei+1]=w;
				wei++;
			}
		}
		for(long long v=1;v<=wei;v++) ans[p[v]]++;
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}
