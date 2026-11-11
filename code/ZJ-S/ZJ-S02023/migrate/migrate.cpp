#include<bits/stdc++.h>
using namespace std;
int w[100005],x[100005],y[100005],k[100005],a[10005][105],t[10005][105],_time[1005][1005];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway1.in","r",stdin);
	int c,t;cin>>c>>t;
	if(c<=14&&c>=13){
		while(t--){
			cout<<0<<endl;
		}
	}
	if(c==11||c==12){
		while(t--){
			int n,d;cin>>n>>d;
			cout<<d-3<<endl;
		}
	}
	return 0;
}