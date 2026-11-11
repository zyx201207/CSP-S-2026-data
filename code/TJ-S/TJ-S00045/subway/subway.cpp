#include<bits/stdc++.h> 
using namespace std;
bool jij=false;
long long ans=0;
long long c,n,m,d,q;
long long p[101][101];
int k[50001];
int x[50001];
int y[50001];
int mnmn(int mn,int g){
	
	ans+=p[mn][mn];
	int min=9999999;
	int mh;
	int h=-1;
	for(int j=0;j<=51;j++){
		if(p[mn][j]!=0){
			if(p[mn][j]<min){
				min=p[mn][j];
				mh=j;
			}
			if(j==x[g]){
				h=j;
				jij=true;
				return h;
			}
		}
	}
	
	ans+=min;
	
	mnmn(mh,g);
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>c>>n>>m>>d>>q;
	long long w1[m];
	long long a[n][101];
	long long t[n][101];
	for(long long i=0;i<m;i++){
		cin>>w1[i];
	} 
	
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			p[a[i][j]][a[i][j]]=t[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i]-1;j++){
			p[a[i][j]][a[i][j+1]]=t[i][j+1];
			p[a[i][j+1]][a[i][j]]=t[i][j+1];
		}
	}
	for(int i=0;i<q;i++){
		ans=0;
		ans+=w1[y[i]-1];
		int fg=mnmn(y[i],i);
		ans+=p[fg][fg];
		ans+=w1[x[i]-1];
		cout<<ans<<"\n";
	}
	return 0;
}
