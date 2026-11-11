#include<bits/stdc++.h>
using namespace std;
#define lint long long
lint l[500005],r[500005];
lint a[500005],ans[500005];
lint n,m;
bool flag;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//  写一半没时间了，g了[哭] 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		l[i]=1e8;
	}
	for(int i=n;i>=1;i--){
		if(r[a[i]]==0){
			r[a[i]]=i;
		}
		else{
			l[a[i]]=i;
			flag=1;
		}
		if(flag==0){
			for(int j=1;j<=m;j++){
				if(r[j]>0){
					ans[j]++;
				}
			}
		}
		else{
			lint ll,rr;
			ll=1e8;
			rr=-1;
			for(int j=i;j<=n;j++){
				if(ll>l[a[i]] && l[i]!=1e8){
					ll=i;
				} 
				if(rr<r[a[i]] && r[i]!=0){
					rr=i;
				}
			}
			for(int j=1;j<=m;j++){
				if(l[j]<=ll || r[j]>=rr){
					ans[j]++;
				}
			}
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
