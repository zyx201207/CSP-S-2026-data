#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+505;
int c,t,n,d,a[N],minn,sum2;

void dfs(int x,int y,int sum){
	if(sum2>2 || sum>minn)
	return ;
	if(x==y){
		if(sum<minn)
		sum2=1,minn=sum;
		else
		sum2++;
		return ;
	}for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,sum+1);
		}else{
			break;
		}
	}
}

signed main(){

freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>c>>t;
if(c==11 || c==12){

while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(d<=a[2]-a[1]){
		cout<<0<<"\n";
	}else{
		d=d/(a[2]-a[1]);
		cout<<max(n-(2*d)+1,0LL)<<"\n";
	}
}

}else if(c==13 || c==14){

while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(a[n]-a[1]==2*d-1 || a[n]-a[1]==2*d)
	cout<<1<<"\n";
	else
	cout<<0<<"\n";
}
	
}else{

while(t--){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int len=2;i+len<=n;len++){
			sum2=0;
			minn=0x3f3f3f3f;
			dfs(i,i+len,1);
			if(sum2==2LL){
				ans++;
			}
		}
	}cout<<ans<<"\n";
}

}

return 0;
}
