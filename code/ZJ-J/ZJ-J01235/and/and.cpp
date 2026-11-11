#include<bits/stdc++.h>
using namespace std;
int aa[200010][40];
long long bb[200010];
int ans[40];
int ans1=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,a,k,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>bb[i];
	} 
	sort(bb+1,bb+n+1);
	for(int i=1;i<=n;i++){
		a=bb[i];
		k=1;
		while(a!=0){
			if(a%2==1){
				aa[i][k]=1;
			}else{
				aa[i][k]=0;
			}	
			a/=2;	
			maxx=max(maxx,k);
			k++;
		}
	} 
	for(int i=maxx;i>=1;i--){
		long long cnt=0;
		int arr=1;
		while(arr<=n){
			if(aa[arr][i]==1){
				cnt++;
			}
			arr++;
			
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(aa[j][i]==0){
					for(int g=i;g>=1;g--){
						aa[j][g]=0;
					}
				}
			
			}
			ans[i]=1;
		}else if(cnt<n){
			ans[i]=0;
		}
	}
	int r=1;
	for(int i=1;i<=30;i++){
		if(ans[i]==1){
			ans1+=r;
		}
		r*=2;
	}
	cout<<ans1;
	return 0;
} 
