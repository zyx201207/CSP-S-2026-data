#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,a[2000006],d,x,ans,f[5005][5005],ff[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==25){
		cout<<"leilekunle,hedongpengteyin!";
		return 0;
	}
	while(t--){
		cin>>n>>k;
		bool fl=1,fll=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1 && a[i]-a[i-1] != a[2]-a[1]){
				fl=0;
//				cout<<i<<"\n";
			}
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
//		if(fl && n>300){ //11,12
//			d=a[2]-a[1];
//			k/=d;
//			ans=0;
//			for(int i=1;i<k && n-k-i>0;i++){
//				ans+=n-k-i;
//			}
//			cout<<ans<<"\n";
//			continue;
//		}
//		for(int i=1;i<=n;i++){
//			if(a[i]-k<=a[1] && a[i]+k>=a[n]){
//				fll=1;
//				x=i;
//			}
//		}
//		if(fll && n>300){ //13,14
//			for(int i=x;i<n;i++){
//				a[i]=a[i+1];
//			}
//			n--;
//			
//		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=(ll)9e18;
				if(i==j){
					f[i][j]=0;
				}
				ff[i][j]=0;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(k<=i) continue;
				for(int j=k+1;j<=n;j++){
					ll xxx=f[i][j];
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					if(a[j]-a[i]<=k){
						f[i][j]=1;
						ff[i][j]=0;
					}
					if(f[i][j]==xxx){
						ff[i][j]++;
//						cout<<i<<" "<<j<<" "<<k<<"\n";
					}else{
						ff[i][j]=1;
//						cout<<i<<" "<<j<<" "<<k<<"\n";
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ff[i][j]==2){
					ans++;
//					cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<ff[i][j]<<"\n";
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
//luogu_liuyuxiaozaizai

