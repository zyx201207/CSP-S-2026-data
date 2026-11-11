#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,m,a[2000005],e[305],b[2000005],ans;
string s[2000005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		b[i]=1;
		cin>>a[i];
		int j=1;
		while(j<=30){
			s[i]=char(a[i]%2+48)+s[i];
			a[i]/=2;
			j++;
		}
		for(int j=0;j<=29;j++){
			if(s[i][j]=='1')e[j+1]++;
		}
	}
	for(int i=1;i<=30;i++){
		//cout<<e[i]<<' ';
		if(e[i]>=m){
			int f=1;
			for(int j=1;j<=30-i;j++){
				f*=2;
			}
			ans+=f;
			for(int j=1;j<=n;j++){
				if(s[j][i-1]!='1' and b[j]==1){
					//cout<<s[j]<<' ';
					b[j]=0;
					for(int k=0;k<=29;k++){
						if(s[j][k]=='1'){
							e[k+1]--;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
