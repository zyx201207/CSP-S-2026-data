#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		long long maxx=-9999;
		long long t=a[1];
		long long cnt=1;	
		for(int i=2;i<=n;i++){
			if(a[i]!=t){
				maxx=max(maxx,cnt);
				t=a[i];
				cnt=1;
			}
			else{
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
		cout<<maxx;
		return 0;
	}	
	return 0;
}
