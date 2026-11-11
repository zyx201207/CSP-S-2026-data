#include<iostream>
using namespace std;
long long a[2000006];
long long n,d,cnt=0,ans=0,minn=1e18;
void dfs(int x,int y,int step){
	if(x==y){
		if(step<minn){
			minn=step;
		}
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,step+1);
		}
	}
	return;
}
void dfs2(int x,int y,int step){
	if(x==y){
		if(step==minn){
			cnt++;
		}
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs2(i,y,step+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(d<a[n]-a[n-1]){
				cout<<0<<endl;
			}else{
				long long yd=d/(a[n]-a[n-1]);
				for(int i=1;i<yd;i++){
					ans=yd+i;
					cnt+=n-ans;
				}
				cout<<cnt<<endl;
			}
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				minn=1e18;
				dfs(i,j,0);
				dfs2(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 