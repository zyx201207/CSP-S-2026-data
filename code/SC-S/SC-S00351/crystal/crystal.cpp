#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
long long tot;
double kkk;
long long o;
int ans;
long long a[500005],b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	tot=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		tot+=a[i];
	}
	sort(b+1,b+n);
	sort(a+1,a+n);
	
	
	if(n%2){
		int flag=b[n/2+1];
	//	ans++;
		int maxn=m;
		for(int i=n/2;i>=1;i--){
			int cmo=flag-b[i];
			if(cmo>maxn) break;
			else{
				maxn-=cmo;
				b[i]=flag;
				//ans++;
			}
		}		
		for(int i=1;i<=n;i++)
			if(b[i]==flag) ans++;

		for(int i=n/2+2;i<=n;i++){	
		//cout<<"maxn="<<maxn<<"\n";
			int tpu=maxn;
			if(b[i]==flag) continue;
			else{
				int tuu=b[i]-flag;
				int yu=0;
				for(int j=i;j<=n;j++){
					if(b[j]==b[i]) yu++;
					else break; 
				}				
				int yy=ans-yu;
				int cntt=0;
				for(int j=1;j<=yu;j++){
					cntt+=(b[i]-a[i]);
				} 
				if(maxn>ans*tuu){
					for(int j=1;j<i;j++){
						b[j]=b[i];
						maxn-=tuu;
					}
					flag=b[i];
					ans+=yu;
					i=i+yu-1;
					continue;
				}
				else if(cntt>yy*tuu&&maxn<=yy*tuu){
					maxn+=cntt;
					for(int j=1;j<=yu;j++){
						b[j]=a[j];
					}
					for(int j=yu+1;j<=i;j++){
						b[j]=b[i];
						maxn-=tuu;
					}
					flag=b[i];
					i=i+yu-1;
					continue;
				}
				else break;
			}
		}	

		cout<<ans;
		return 0;
	}
	else{
		int flag=b[n/2+1];
		
		int maxn=m;
		for(int i=n/2;i>=1;i--){
			int cmo=flag-b[i];
			if(cmo>maxn) break;
			else{
				maxn-=cmo;
				b[i]=flag;
				//ans++;
			}
		}
		for(int i=1;i<=n;i++)
			if(b[i]==flag) ans++;

		for(int i=n/2+2;i<=n;i++){
			//	cout<<"maxn="<<maxn<<"\n";	
			int tpu=maxn;
			if(b[i]==flag) continue;
			else{
				int tuu=b[i]-flag;
				int yu=0;
				for(int j=i;j<=n;j++){
					if(b[j]==b[i]) yu++;
					else break; 
				}				
				int yy=ans-yu;
				int cntt=0;
				for(int j=1;j<=yu;j++){
					cntt+=(b[i]-a[i]);
				} 
				if(maxn>ans*tuu){
					for(int j=1;j<i;j++){
						b[j]=b[i];
						maxn-=tuu;
					}
					flag=b[i];
					ans+=yu;
					i=i+yu-1;
					continue;
				}
				else if(cntt>yy*tuu&&maxn<=yy*tuu){
					maxn+=cntt;
					for(int j=1;j<=yu;j++){
						b[j]=a[j];
					}
					for(int j=yu+1;j<=i;j++){
						b[j]=b[i];
						maxn-=tuu;
					}
					flag=b[i];
					i=i+yu-1;
					continue;
				}
				else break;
			}
		}	

	
		int ans1=ans;
		ans=0;
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		
		flag=b[n/2];
		
		maxn=m;
		for(int i=n/2-1;i>=1;i--){
			int cmo=flag-b[i];
				//cout<<"cmo="<<cmo<<"\n";	
			if(cmo>maxn) break;
			else{
				//cout<<"maxn="<<maxn<<"\n";
				maxn-=cmo;
				b[i]=flag;
				//ans++;
			}
		}	
		for(int i=1;i<=n;i++)
			if(b[i]==flag) ans++;

		for(int i=n/2;i<=n;i++){
			//	cout<<"maxn="<<maxn<<"\n";	
			int tpu=maxn;
			if(b[i]==flag) continue;
			else{
				int tuu=b[i]-flag;
				int yu=0;
				for(int j=i;j<=n;j++){
					if(b[j]==b[i]) yu++;
					else break; 
				}				
				int yy=ans-yu;
				int cntt=0;
				for(int j=1;j<=yu;j++){
					cntt+=(b[i]-a[i]);
				} 
				if(maxn>ans*tuu){
					for(int j=1;j<i;j++){
						b[j]=b[i];
						maxn-=tuu;
					}
					flag=b[i];
					ans+=yu;
					i=i+yu-1;
					continue;
				}
				else if(cntt>yy*tuu&&maxn<=yy*tuu){
					maxn+=cntt;
					for(int j=1;j<=yu;j++){
						b[j]=a[j];
					}
					for(int j=yu+1;j<=i;j++){
						b[j]=b[i];
						maxn-=tuu;
					}
					flag=b[i];
					i=i+yu-1;
					continue;
				}
				else break;
			}
		}
	//	cout<<"ans1="<<ans1;
	//	cout<<"ans2="<<ans;	
		ans=max(ans1,ans);
		cout<<ans;
		return 0;
	}
} 