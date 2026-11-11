#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long c,n,d,ll,x,w[N],k,maxx[N],a,t[500],m,q,sum,l;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
		l=0;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a>>t[i];
			sum+=t[i];
		}
		maxx[++l]=sum;
	}
	sort(maxx+1,maxx+l);
	for(int i=1;i<=q;i++){
		cout<<maxx[i];
	}
	return 0;
	
} 
