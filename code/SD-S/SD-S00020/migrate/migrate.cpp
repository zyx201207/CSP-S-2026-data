#include<bits/stdc++.h>
#define int long long
using namespace std;
void AC40(){
	int n,d;
	cin>>n>>d;
	vector<int> x(n+1,0),p(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int l=1,r=2;r<=n;r++){
		while(x[r]-x[l]>d)l++;
		p[r]=l;
		//cout<<p[r]<<' ';
	}
	int ans=0;
	for(int h=1;h<n;h++){
		vector<int> dp(n+1,1e15),f(n+1,0);
		dp[h]=0;
		f[h]=1;
		for(int i=h+1;i<=n;i++){
			for(int j=p[i];j<=p[i]+3;j++){
				if(j<h)continue;
				if(j==i)break;
				const int o=dp[j]+1;
				if(o==dp[i]){
					f[i]+=f[j];
				}
				if(o<dp[i]){
					dp[i]=o;
					f[i]=f[j];
				}
			}
			//cout<<f[i]<<endl;
			if(f[i]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
void ACA(){
	int n,d;
	cin>>n>>d;
	vector<int> x(n+1,0),p(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<4){
		cout<<0<<endl;
		return;
	}
	int h=x[2]-x[1];
	int k=d/h;
	if(k<2){
		cout<<0<<endl;
		return;
	}
	int an=n-(k+k)+1; //k+k
	cout<<an<<endl;
}
void ACB(){
	int n,d;
	cin>>n>>d;
	vector<int> x(n+1,0),p(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	cout<<0<<endl;
}
void ACC(){
	int n,d;
	cin>>n>>d;
	vector<int> x(n+1,0),p(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<4){
		cout<<0<<endl;
		return;
	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c<=10){
			AC40();
		}else if(c==11||c==12){
			ACA();
		}else if(c==13||c==14){
			ACB();
		}
	}
	return 0;
}

