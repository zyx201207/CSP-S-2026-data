#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n;
long long sum;
struct stu{
	int a;
	char s;
};
stu G[N],K[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>G[i].a>>G[i].s;
	}
	for(int i=1;i<=n;i++){
		K[i].a=G[n-i+1].a;
		K[i].s=G[n-i+1].s;
	}
	int gi=1,ki=1;
	while(gi<=n&&ki<=n){
		if(G[gi].s!=K[ki].s)sum+=min(G[gi].a,K[ki].a);	
		if(G[gi].a>K[ki].a){
			G[gi].a-=K[ki].a;
			ki++;
		}
		else if(G[gi].a<K[ki].a){
		    K[ki].a-=G[gi].a;
			gi++;
		}
		else gi++,ki++;
	}
	cout<<sum/2;
	return 0;
} 
