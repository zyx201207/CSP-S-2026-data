#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int ansleft,ansright,sumleft,sumright;
	for(int i=n;i>=1;i--){
		if(a[i]*i-pre[i]<=m){
			ansleft=i;
			sumleft=a[i];
			sumright=a[i+1];
			break;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==sumright) ansright=i;
//	cout<<sumleft<<" "<<ansleft<<" "<<sumright<<" "<<ansright<<"\n"; 
	for(int i=1;i<=n;i++){
		if((ansright-i)*a[ansright]-pre[ansright]+pre[i+1]<=m){
			ansright-=i;
//			cout<<i<<" "<<pre[i]<<"\n";
			break;
		}
	}
//	cout<<ansleft<<" "<<ansright<<"\n";
	cout<<max(ansleft,ansright);
	return 0;
} 