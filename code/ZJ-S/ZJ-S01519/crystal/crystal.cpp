#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,ans=1;
int a[maxn],b[maxn];

int qwq[maxn],awa[maxn];

void init(){
	//b:
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	//qwq:
	for(int i=1;i<=n;i++){
		qwq[i]=qwq[i-1]+b[i]*i;
	}
	//awa
	for(int i=1;i<=n;i++){
		awa[i]=awa[i-1]+b[i];
	}
	return ;
}

bool check(int target){
	for(int i=1;i<=n-target+1;i++){
		if(qwq[i+target-1]-qwq[i-1]-i*awa[i+target-1]
			+i*awa[i-1]<=m){
			return true;
		}
//		cout<<i<<" "<<qwq[i+target-1]-qwq[i-1]-i*awa[i+target-1]
//			+i*awa[i-1]<<"\n";
	}
	return false;
}

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios_base::sync_with_stdio(0); 
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	init();	
	
//	cout<<"a:   ";
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<"\nb:   ";
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
//	cout<<"\nqwq: ";
//	for(int i=1;i<=n;i++){
//		cout<<qwq[i]<<" ";
//	}
//	cout<<"\nawa: ";
//	for(int i=1;i<=n;i++){
//		cout<<awa[i]<<" ";
//	}
//	cout<<"\n";
//	check(3);

	int lt=1,rt=n;
	while(lt<rt){
		int mid=(lt+rt+1)>>1;
		if(check(mid)) lt=mid;
		else rt=mid-1;
//		cout<<lt<<" "<<rt<<"\n";
	}
	cout<<lt;
	return 0;
} 
/**

he dan tan zuo , yi zi bao zha

wozazhemecai 

bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
**/
