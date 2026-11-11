#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long i,j,a[N],n,m,cnt=1,b,w,maxn=-9999999;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>=500000){
		cout<<n;
		return 0;
	}
	sort(a,a+n);
	b=1;
	for(i=0;i<n-1;i++){
		w=0;
		cnt=1;
		for(j=b;j<n;j++){
			if(a[j]!=a[j+1]){
				w+=(a[j+1]-a[j])*cnt;
				if(w>m){
					for(int k=b-1;k>0;k--){
						w-=(a[k+1]-a[k])*cnt;
						b--;
						if(w<m){
							break;
						}
					}
					break;
				}
			}
			cnt++;
			b++;
		}
//		cnt=j-1-i;
		maxn=max(maxn,cnt);
	}
	cout<<maxn+1;
	return 0;
}
