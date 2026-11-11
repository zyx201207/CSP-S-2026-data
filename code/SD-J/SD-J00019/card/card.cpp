#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int MAXN=5e5+2;
const int MAXM=3e5+2;
int a[MAXN];
bool ins[MAXN];
int tong[MAXN];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=1;
	int nowcnt=1;
	int lastans=0;
	for (int i=2;i<=n;i++){
		if (a[i]==a[last]){
			nowcnt++;
		}
		else{
			int anss=lastans+nowcnt;
			cout<<anss<<' ';
			lastans=anss;
			last=i;
			nowcnt=1;
		}
	}
	if (lastans!=0)cout<<lastans+nowcnt<<endl; 
	return 0;
}
