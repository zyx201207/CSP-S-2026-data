#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans,a[2000005];
bool sjd(int x,int y){
	int zkl,ls=0,i=x;
	while(i<y){
		if(a[i+1]-a[i]>d) return 0;
		int l=0;
		while(l+a[i]<d){
			l+=a[i];
			i++;
		}
		zkl++;
	}
	
	
	if(ls==2){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sjd){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
