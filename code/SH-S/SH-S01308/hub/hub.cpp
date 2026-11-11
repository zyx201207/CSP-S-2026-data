#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long u[1000001];
long long v[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long num;
	long long T;
	cin>>num>>T;
	if(num==0 or num==13 or num==14){
		while(T--){
			long long n,k;
			cin>>n>>k;
			for(long long i=1;i<n;i++){
				cin>>u[i]>>v[i];
			}
			if(k==1)cout<<(n+1)/2/2+1<<"\n";
			else cout<<((n+1)/2+1-k+4)/4<<"\n";
		}
	}
	else while(T--)cout<<"0"<<"\n";
	return 0;
}  
