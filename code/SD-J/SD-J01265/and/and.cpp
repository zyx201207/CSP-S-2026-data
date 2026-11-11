#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k;
long long a[N],qpow[35],head[35];
bool t[N][35],flag[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i],cnt=0;
		bool z[35]={0};
		while(x!=0){
			cnt++;
			if(x&1){
				z[cnt]=1;
			}
			x/=2;
		}
		for(int j=31,w=1;w<=cnt;w++,j--){
			t[i][j]=z[w];
		}
	}
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			head[i]+=t[j][i];
		}
	}
	for(int i=1;i<=30;i++){
		qpow[i]=pow(2,31-i);
	}
	qpow[31]=1;
	long long ans=0;
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			if(flag[j]&&t[j][i]){
				head[i]--;
			}
		}
		if(head[i]>=k){
			ans+=qpow[i];
			for(int j=1;j<=n;j++){
				if(t[j][i]==0){
					flag[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
