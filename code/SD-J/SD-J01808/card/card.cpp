#include<bits/stdc++.h>
using namespace std;
int a[50000],count[50000],pos[50000],card[50000];
int main(){
	//freopen("xxx.in","r",stdin);
	//freopen(""xxx.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin >> n >>m;
	memset(count,-1,sizeof(count));
	for (long long i=1;i<=n;++i){
		cin >> a[i];
	}
	for (long long i=n;i<=1;--i){
		memset(pos,-1,sizeof(pos));
		memset(card,-1,sizeof(card));
		for (long long j=n-i+1;j<=n;++j){
			if (pos[a[j]]!=-1){
				for (int x=pos[j];x<=j;++x){
					card[x]=-1;
				}
			}
			card[j]=a[j];
			pos[a[j]]=j;
		}
		for(long long j=n-i+1;j<=n;++j){
			if (pos[a[j]]!=-1){
				count[a[j]]++;
			}
		}
	}
	for (long long i=1;i<=n;++i){
		cout << count[i] << " ";
	}
} 
