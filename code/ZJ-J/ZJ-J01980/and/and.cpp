#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[1000010];
bool bin[1000010][40];//up=32
bool chos[1000010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		chos[i]=1;
	}
	sort(a,a+n,[](int a,int b){
		return a>b;
	});
	for(int i=0;i<n;i++){
		int t=a[i];
		for(int j=0;j<32;j++){
			bin[i][j]=t&1;
			t>>=1;
		}
	}
	int c;
	for(c=31;c>=0;c--){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(bin[i][c])cnt++;
		}
		if(cnt>=m){
			break;
		}
	}
	if(c<0){
		cout<<0;
		return 0;
	}
	for(int cc=c;cc>=0;cc--){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(chos[i]){
				if(bin[i][cc])cnt++;
			}
		}
		if(cnt<m){
			continue;
		}
		for(int i=0;i<n;i++){
			if(!bin[i][cc]){
				chos[i]=0;
			}
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++){
		if(chos[i]){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}