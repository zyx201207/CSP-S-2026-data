#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,t=-1,b[500005],pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//if(n<=16&&m<=1000){
		for(int l=1;l<=n;l++){
			for(int r=n;r>=l;r--){
				ans=0;
				for(int k=l;k<=r;k++){
					ans+=a[r]-a[k];
				}
				if(ans<=m&&r-l+1>t){
					t=r-l+1;
				}
			}
		} 
		cout<<t<<endl;
	/*}else{
		for(int i=2;i<=n;i++){
			pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
		}
		for(int )
		
	}
	
	
	
	5 8
	-3 -1 2 2 7
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		for(int i=l;i<=r;i++){
			ans+=b[r]-b[i];
		}
		if(m<ans)
	}*/ 
}
