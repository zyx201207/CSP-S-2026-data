#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt = -1;
long long add(){
	long long ma = -1,t;
	long long b[n+5];
	for(int i=1;i<=n;i++){
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		long long ans = a[i];
		t = 1;
		for(int j=i+1;j<=n;j++){
			if(a[j]>ans) break;
			if(ans == a[j]){
				ans+=a[j];
				t++;
			}
			
		}
		ma = max(ma,t);
	}
	return ma;
}
void stal(int w,int c){
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<add();
//	cout<<endl;
	cnt = max(cnt,add());
	if(c == 0||w>n) return;
	stal(w+1,c);
	a[w]++;

	stal(w,c-1);
	a[w]--;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stal(1,m);
	cout<<cnt;
	return 0;
}
