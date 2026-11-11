#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int maxa=2e5+10;
int a[maxa];
long long dp[maxa];
bool book[maxa];
int nub[maxa],sex[maxa];//nub代表有多少个相同数，sex代表相隔相同距离多少有多少个数字;
long long low[maxa];//low=nub*sex,贪心,代表合并果子怎么选的区间； 
int cuzh=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(book,0,sizeof(book));
	memset(nub,0,sizeof(nub));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		book[a[i]]=1;
		nub[a[i]]++;
	}
	for(int i=1;i<=n;i++)cuzh=max(cuzh,nub[i]);
	//sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(book[i]==1&&book[i-j]==1){
				sex[j]++; 
				low[j]+=j*nub[i-j]; 
			}
		}
	}
	int ans=cuzh;
	while(m){
		for(int i=1;i<=n;i++){
			if(m<low[i]){
				ans+=m;
				break;
			}
			else{
				m-=low[i];
				ans+=low[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}