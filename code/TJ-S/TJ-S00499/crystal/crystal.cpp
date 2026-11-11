#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long f=1;
	long long cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			f++;
			continue;
		}
		bool kl=0;
		while(1){
			if(cnt+f>m){
				kl=1;
				break;
			}
			cnt+=f;
			a[i]++;
			if(a[i]==a[i+1]){
				f++;
				break;
			}
			
		}
		if(kl){
			break;
		}
	}
	cout<<f;
	return 0;
}
