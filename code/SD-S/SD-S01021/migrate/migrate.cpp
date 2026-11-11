#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long  c,t;
	long long n,d;
//	cin>>n>>d;
	
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
//			x[i]+=1e18;
		}
		
		long long pos,x_fir,x_sec,x_thir;
		for(int i=1;i<=n;i++){
			if(x[i]+d<=x[n]){
				pos=upper_bound(x+1+i,x+1+n,x[i]+d)-x-1;
			}
			if(pos-i<=1) continue;
//			cout<<pos<<" \n";
//			long long 
			x_fir=x[pos];
			x_sec=x[pos-1];
			if(pos-i>=3){
				x_thir=x[pos-2];
			}
//			cout<<pos<<"\n\n";
//			cout<<x_fir<<" "<<x_sec<<"\n";
			long long temp1=upper_bound(x+1+pos,x+1+n,x_fir+d)-x-1;
			long long temp2=upper_bound(x+1+pos,x+1+n,x_sec+d)-x-1;
			long long temp3=upper_bound(x+1+pos,x+1+n,x_thir+d)-x-1;
			if(temp2>temp3){
				ans+=temp1-temp2+1;
			}else{
				ans+=temp1-temp3;
			}
		}
		cout<<ans<<"\n";
	}
}

