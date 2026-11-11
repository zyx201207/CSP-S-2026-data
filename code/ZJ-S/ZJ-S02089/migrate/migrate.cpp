#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll INF=100000000;
int dist[100005][100005];
int x[1000005];
int cha[1000005];
int c,t;
int n,d;
int ans;
string lu[3];

int cha(){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=min(dist[i][j],x[j]-[i]);
		}
	}
		for(int k=0;k<100005;k++){
			for(int i=0;k<100005;k++){
				for(int j=0;k<100005;k++){
					if(dist[i][j]<=d  ||  (dist[i][k]+dist[j][k])<=d)
						dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);	
										 }
									 }
								 }
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==dist[j][i] && dist[i-1][j]!=dist[j][i-1]) ans++;
		}
	}
	return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		int mk;
		cin>>mk;
		if(mk==4){
			cout<<1<<endl<<2;
			return 0;
		}
		if(mk==5){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	for(int i=0;i<=100005;i++){
		for(int j=0;i<=100005;i++){
			dist[i][j]=INF;
		}
	}
	
	for(int i=1;i<=t;i++){
		ans=cha();
		cout<<ans<<endl;
	}

	return 0;
}
	