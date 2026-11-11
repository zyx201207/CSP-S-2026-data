#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int a[10005];
int cnt=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	double sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	sum=(int)sum;
	int num=(int)sum;
	int t=0;//sum的下标 
	for(int i=1;i<=n;i++){
		if(a[i]==sum){
			t=i;
		}
	}
	int b=0;
	if(t==0){
		for(int i=1;i<=n;i++){
			int b=min(abs(a[i]-num),abs(a[i+1]-num));//b代表在啊a数组中哪个数最接近sum 
			if(abs(a[i]-num)==abs(a[i+1]-num)){
				b=a[i];
			}	
		}
	}
	cout<<b+1; 
	return 0;
}