#include <bits/stdc++.h>
using namespace std;
int C,T,N;
unsigned long long D;
long long A[2000010];
long long ans(){
	long long cha=A[2]-A[1];
	if(cha*2>D)return 0;
	if(cha*2==D){
		return max(0,N-3);
	}
	long long be=D/cha+1;
	long long ans=N-((be-1)*2)+1;
	return max((long long)0,ans);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>N>>D;
		for(int i=1;i<=N;i++){
			cin>>A[i];
		}
		cout<<ans()<<"\n";
	}
	return 0;
}
