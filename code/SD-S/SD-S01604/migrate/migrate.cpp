#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int maxn=2e6+10;
ll c,t,n,dis,a[maxn],d; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){// A
			while(t--){
			cin>>n>>dis;
			for(int i=1;i<=n;i++)cin>>a[i];
			d=a[2]-a[1];
			if(dis<d*2)cout<<"0\n";
			else{
	//			cout<<n<<" ---> ";
				int l=dis/d;
				int r=l+1;
	//			cout<<n<<" "<<dis<<" "<<l<<" "<<r<<" "<<d<<"\n";
				if(dis>=(n-1)*d)cout<<0<<"\n";
				else cout<<n-(l+r+1)+3<<"\n";
			}
		}
	}
	else{// BF
		
	}
	return 0;
}
/*

打补丁写了特殊性质A，暴力不会打不会枚举状态。
 
*/
