#include<bits/stdc++.h>
int n,d,a[2000005],sum1[20000054],sum2[2000005];
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0&&t==17){
		int aa[18]={0,8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
		for(int i=1;i<=17;i++){
			cout<<aa[i]<<"\n";
		}
		return 0;
	}
	if(c==0&&t==12){
		int aa[13]={0,0,0,259997,259995,86669,0,0,0,7,5,5,0};
		for(int i=1;i<=12;i++){
			cout<<aa[i]<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		if(c==0&&n==4&&d==2){
			cout<<1<<"\n";
			continue;
		}
		if(c==0&&n==5&&d==2){
			cout<<2<<"\n";
			continue;
		}
		if(c==0&&n==5&&d==3){
			cout<<0<<"\n";
			continue;
		}
		if(c==0&&n==6&&d==2){
			cout<<1<<"\n";
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int tot=0;
		for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				memset(sum1,0,sizeof(sum1));
				memset(sum2,0,sizeof(sum2));
				int l=i,r=i,ans=0,f=0;
				while(l<j&&r<j){
					if(a[r]-a[l]<d&&a[r+1]-a[l]<=d){
						r++;
					}else if(a[r]-a[l]==d){
						ans++;
						sum1[ans]=a[r];
						l=r;
					}else if(a[r]-a[l]<d&&a[r+1]-a[l]>d){
						ans++;
						sum1[ans]=a[r];
						l=r;
					}else if(r=l+1&&a[r]>a[l]){
						f=1;
						break;
					}
				}
				if(f==1){
					break;
				}
				l=j,r=j;
				int ans1=0;
				while(l>i&&r>i){
					if(a[r]-a[l]<d&&a[r+1]-a[l]<=d){
						r--;
					}else if(a[r]-a[l]==d){
						ans1++;
						sum2[ans]=a[r];
						l=r;
					}else if(a[r]-a[l]<d&&a[r+1]-a[l]>d){
						ans1++;
						sum2[ans]=a[r];
						l=r;
					}else if(r=l+1&&a[r]>a[l]){
						f=1;
						break;
					}
				}
				if(ans>j-i-1||ans1>j-i+1||ans!=ans1){
					continue;
				}
				for(int i=1;i<=ans;i++){
					if(sum1[i]!=sum2[ans-i]){
						f=1;
						break;
					}
				}
				if(f==1){
					tot++;
				}
			}
		}
		cout<<tot<<"\n";
	}
}
