#include<bits/stdc++.h>
using namespace std;
long long l[2000005];
struct node{
	long long a,b;
}p[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,k,o=-1,f=0,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			if(i>=4&&l[i]-l[i-1]<=k&&l[i]-l[i-2]<=k&&l[i]-l[i-3]>k&&l[i-2]-l[i-3]<=k&&l[i-1]-l[i-3]<=k){
				f=1;
				ans++;
				p[ans].b=i;
				p[ans].a=i-3;
			}
		}
		o=l[2]-l[1];
		for(int i=2;i<n;i++){
			if(l[i+1]-l[i]!=o){
				o=0;
				break;
			}
		}
		if(o){
			if(o*2<k){
				cout<<"0\n";
				continue;
			}
			cout<<n-3<<"\n";
			continue;
		}
		int g=ans;
		if(!f){
			cout<<0<<"\n";
			continue;
		}
		f=0;
		for(int i=p[1].a;i>=3;i--){
			if(l[i]-l[i-1]<=k&&l[i]-l[i-2]>k){
				ans++;
			}else{
				break;
				f=1;
			}
		}
		if((!f&&ans>g)||p[1].a==2){
			if(l[2]-l[1]<=k){
				ans++;
			}
		}

		for(int i=2;i<=g;i++){
			for(int j=p[i].a;j>=p[i-1].a+1;j--){
				if(l[j]-l[j-1]<=k&&l[j]-l[j-2]>k){
					ans++;
				}else{
					break;
				}
			}
			for(int j=p[i].b;j<=p[i+1].b;j++){
				if(l[j+1]-l[j]<=k&&l[j+2]-l[j]>k){
					ans++;
				}else{
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
