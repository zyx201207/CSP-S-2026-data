#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005],num[35][200005],n=0,m=0;
bool f[200005],flag=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i],cnt=0;
		while(k){
			int w=k%2;
			if(w){
				num[cnt][0]++;
				num[cnt][num[cnt][0]]=i;
			}
			k/=2;
			cnt++;
		}
	}
	int ans[50],cnt=0;
	for(int i=32;i>=0;i--){
		if(num[i][0]>=m){
			if(!flag){
				ans[++cnt]=i;
				for(int j=1;j<=num[i][0];j++)f[num[i][j]]=1;
				flag=1;
				continue;
			}
			int cnt1=0;
			for(int j=1;j<=num[i][0];j++) if(f[num[i][j]])cnt1++;
			if(cnt1>=m){
				ans[++cnt]=i;
				int t=1;
				for(int j=1;j<=n;j++){
					if((j!=num[i][t])&&(f[j]))f[j]=0;
					else if(j==num[i][t])t++;
				}
			}
		}
	}
	long long anss=0;
	for(int i=1;i<=cnt;i++)anss+=pow(2,ans[i]);
	cout<<anss;
	return 0;
}

