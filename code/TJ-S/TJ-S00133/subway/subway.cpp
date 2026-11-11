#include<bits/stdc++.h>
using namespace std;
int l[510][500010];
long long c,n,m,d,q;
long long x,y;long long lans=100000000000;
int ct[500010]={};
void s(long long i,long long j,long long ans){
	long long ans1=ans;ans1+=l[i][j];
	if(j==y){
		lans=min((ans1+ct[j]),lans);
		return;
	}
	for(int a1=i+1;a1<=n;a1++){
			if(l[a1][j]&&a1!=i){
				ans1+=l[a1][j];
				s(a1,j,ans1);
			}
	}
	for(int a1=j+1;a1<=m;a1++){
		if(l[i][a1]&&a1!=j){
			s(i,a1,ans1-l[i][j]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ct[i];
	}
	for(int i=1;i<=n;i++){
		int g;cin>>g;
		for(int j=1;j<=g;j++){
			int k;cin>>k;
			cin>>l[i][k];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		s(0,x,ct[x]);
		cout<<lans<<endl;
	}
	return 0;
} 
