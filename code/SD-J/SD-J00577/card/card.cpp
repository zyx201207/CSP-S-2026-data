#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int desk[N],e;
int ae[N];
int q[N],qs,qe;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		q[++qe]=x;
		//1~qe
	}
	for(int i=1;i<=n;i++){
		e=0;
		qs=i-1;
		while(qs<qe){
			int t=q[++qs];
			int f=0;
			for(int i=1;i<=e;i++){
				if(desk[i]==t){
					f=i;
					break;
				}
			}
			if(f){
				e=f-1;
			}
			desk[++e]=t;
		}
		for(int i=1;i<=e;i++){
			ae[desk[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ae[i]<<" ";
	}
	return 0;
}
