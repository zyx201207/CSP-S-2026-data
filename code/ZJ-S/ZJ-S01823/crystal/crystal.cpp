#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,mm,cnt,ans;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	vector<ll>a(n);
	vector<ll>p(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++)p[i]=a[i]-a[i-1];
	
//	for(int i=1;i<n;i++)cout<<p[i]<<' ';
//	cout<<'\n';
	
	for(int i=1;i<n;i++){
		
		mm=m;
		cnt=1;
		int l=i;
		while(mm-p[l]*(l-i)>=0&&l<n){
//			cnt++;
//			l++;
//			while(p[l]==0&&l<n){
//				cnt++;
//				l++;
//			}
//			do{
//				cnt++;
//				l++;
//			}while(p[l]==0&&l<n);
			if(p[l]==0&&l<n){
				while(p[l]==0&&l<n){
					cnt++;
					l++;
					
				}
			}
			else{
				cnt++;
				l++;
			}
			mm-=p[l]*(l-i);
			
//			cout<<cnt<<"##";
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
