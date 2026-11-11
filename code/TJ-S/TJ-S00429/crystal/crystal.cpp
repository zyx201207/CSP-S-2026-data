#include<iostream>//RP++
using namespace std;
long long n,m,arr[500005],ans,cha;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	cha=arr[2]-arr[1];
	while(1){
		if(m<ans*cha) break;
		m-=(ans++)*cha;
	}
	cout<<ans;
	
	return 0;
} 
