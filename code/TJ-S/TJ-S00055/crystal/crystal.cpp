#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ans=1,di=0;
	long long m;
	cin>>n>>m;
	vector<long long> a(n);
	vector<long long> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	for(int i=n-1;i>0;i--){
		if(b[i]==b[i-1]) b[i]=0;
	}
	if(m<b[0]){
		cout<<0;
		return 0;
	}
	else m-=b[0];
	int i=1;
	for(;i<n;i++){
		if(m>=b[i]) m=m-b[i];
		else break;
	}
	
	cout<<i<<'\n';
//	int k=0;
//	for(int i=k;i<n-1;i++){
//		int w=q(b,k);
//		k+=ab-1;
//		if(w==0&&ans==0) ans+=ab;
//		
//		if(k==0&&m-b[k]<0){
//			ans=0;
//			break;
//		}
//		if(m==0){
//			cout<<ans+ab-1;
//			return 0;
//		}
//		if(m-ans*b[k]<0){
//			ans-=(ans*b[k]*1LL-m)/b[k];
//			if((ans*b[k]-m)%b[k]!=0) ans--;
////			cout<<w<<' '<<k<<' '<<b[k]<<' '<<ab<<' '<<ans<<' '<<m<<' '<<'!'<<'\n';
//			break;
//		}
//		m-=ans*b[k]*1LL;
////		cout<<w<<' '<<k<<' '<<b[k]<<' '<<ab<<' '<<ans<<' '<<m<<'\n';
//		if(w!=0&&ans!=0) ans+=ab;
//		k++;
//		ab=0;
//		if(ans!=0&&w==0) ans++;
//		
//	}
//	if(ans>n) ans--; 
//	cout<<ans;
	return 0;
} 

