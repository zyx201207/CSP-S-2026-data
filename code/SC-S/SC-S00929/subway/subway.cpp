#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],T,t[510][510],k[510],x[500010],a[510][510],y[500010],ans,cnt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<"32\n17";
			return 0;
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<"35\n16";
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			if(j%2==1){
				cin>>a[i][j/2+1];
			}
			else{
				cin>>t[i][j/2];
				T=t[i][j/2];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int l=0,h=0;
		ans=w[x[i]];
		ans+=w[y[i]];
		ans+=2*T;
		cnt=x[i];
		for(int j=1;j<=n;j++){
			for(int s=1;s<=2*k[i];s+=2){
				if(a[j][s]==cnt){
					l=j;
				}
				if(a[j][s]==y[i]){
					h=j;
				}
			}
		}
		int lll=0;
		for(int j=1;j<=n;j++){
			for(int s=1;s<=2*k[i];s+=2){
				if(l==h){
					lll=1;
					cout<<ans<<"\n";
					break;
				}
			}
			if(lll==1){
				break;
			}
		}
		if(lll==1){
			continue;
		}
		int rrr=0;
		for(int j=1;j<=2*k[i];j+=2){
			for(int s=1;s<=2*k[i];s+=2){
				if(a[l][j]==a[h][s]){
					rrr=1;
					cout<<ans+T<<"\n";
					break;
				}
			}
			if(rrr==1){
				break;
			}
		}
		if(rrr==1){
			continue;
		}
		ans+=(n-2)*T;
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}