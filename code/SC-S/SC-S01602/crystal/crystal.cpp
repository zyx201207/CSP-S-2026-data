#include<bits/stdc++.h>
using namespace std;
const int N= 5e5+5;
long long n,m,a[N],total=1;
int mix(long long x){
	if(x%2 == 0){
		return x/2;
	}else{
		return x/2+1;
	}
}
void solve(){
	cin>>n>>m;
	long long n2=mix(n);
	long long b[n2-1];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i= 1;i<n2;i++){
			b[i] = a[n2]-a[i];

		}
	sort(b,b+1+n2); 
	while(m>0){
		for(int i = 1;i<=n2-1;i++){
			if(m == 0) break;
			for(int j = 1;j<=b[i];j++){
				if(b[i] == 0) continue;
				if(m == 0) break;
				m=m-1;
				b[i] = b[i]-1;
			}
		}
		for(int i = 1;i<=n2-1;i++){
			if(b[i] == 0){
				total+=1;
			}else{
				total+=0;
			}
		}
	}
	cout<<total;
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    solve();
	return 0;
}