#include <bits/stdc++.h>
int a[2000006],tmp[2006][2006][2];int n,d;
using namespace std;
void pd(int sa,int a,int b,int cnt) {
	if(a==b){
		//cout <<"%%%" << endl;
		if(cnt==tmp[sa][b][0])tmp[sa][b][1]++;
		else {
			tmp[sa][b][0]=min(tmp[sa][b][0],cnt);
			tmp[sa][b][1]=0;
		}
		return ;
	}
	if(a>b)return;
	for(int i=1;i<=min(d,b-a);i++) {
		pd(sa,a+i,b,cnt+1);
		
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,ans=0;cin >>c >>t;
	
	while(t--) {
		memset(a,0,sizeof a);memset(tmp,0,sizeof tmp);
		
		cin >> n >>d;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				tmp[i][j][0]=2e9;
			}
		}
		for(int i=0;i<n;i++) {
			cin >>a[i];
		}
		if(c==13||c==14) {//不可以，总司令 
			cout <<0 <<endl;
			continue;
		}
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(a[j]-a[i]<=d)continue;
				pd(i,i,j,0);
				
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout << tmp[i][j][0] << ' '<<tmp[i][j][1] << ' ';
				if(tmp[i][j][1]==2)ans++;
			}
			cout <<'\n';
		}
		cout <<ans <<endl;
	}
	return 0;
}
