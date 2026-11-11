#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int inf = 1e18;
const int N = 5e5+5;
int a[N];
int cnt[N];
int R[N];
int lst[N];
int tr[N];
int d[N];
int lowbit(int x){
	return x & -x;
}//[i-lowbit(I)+1,i]
void add(int x){
	for(int i = x;i < N;i += lowbit(i)){
		tr[i]++;
	}
}
int qq(int x){
	int ans = 0;
	for(int i = x;i;i-=lowbit(i)){
		ans+=tr[i];
	}
	return ans;
}
int qu(int l,int r){
	return qq(r)-qq(l-1);
}
void read(int &x){
	char c = getchar();
	while(c!='-'&&!(c>='0'&&c<='9'))c=getchar();
	int f = 1;
	if(c=='-')f = -1;
	x = 0;
	while((c>='0'&&c<='9')){
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
void readc(char &c){
	c = getchar();
	while(c==' ')c=getchar();
}
void solve(){
	int n,m;
	read(n);
	read(m);
	for(int i = 1;i <= n;i++){
		read(a[i]);
		R[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
//	if(n<=5000){
//		for(int i = 1;i <= n;i++){
//			int j = i;
//			while(j<=n){
//				if(R[j]){
//					j=R[j];
//				}
//				else{
//					cnt[a[j]]++;//hai ke yi you hua
//					j++;
//				}
//			}
//		}
//		for(int i=1;i <= m;i++){
//			cout << cnt[i] << ' ';
//		}
//	return;
//	}
	for(int i = 1;i <= n;i++){
		if(!R[i]){
			add(i);
		}
	}
	int fA = 1;
	int cntB = 0;
	for(int i = 1;i < n;i++){
		fA &= (a[i] <= a[i+1]);
		cntB += (a[i]!=a[i+1]);
	}
	if(fA){
		for(int i = n;i >= 1;i--){
			if(a[i]!=a[i+1])cnt[a[i]] += i;
		}
		for(int i=1;i <= m;i++){
			cout << cnt[i] << ' ';
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		int j = i;
		while(j<=n){
			if(R[j]){
				j=R[j];
			}
			else{
//				cnt[a[j]]++;//hai ke yi you hua
//				j++;
				if(j==n){
					cnt[a[j]]++;
					break;
				}
				if(R[j+1]){
					cnt[a[j]]++;
					j++;
					continue;
				}
				if(R[j+2]){
					cnt[a[j]]++;
					cnt[a[j+1]]++;
					j+=2;
					continue;
				}
				int l = j;
				int r = n;
				int res = j;
				while(l <= r){
					int mid = l + r >> 1;
					if(qu(j,mid)==mid-j+1){
						l = mid + 1;
						res = mid;
					}
					else{
						r = mid - 1;
					}
				}//[l,res]dou shi 1
				d[j]++;
				d[res+1]--;
				j = res+1;
			}
		}
	}
	int sum = 0;
	for(int i = 1;i <= n;i++){
		sum += d[i];
		cnt[a[i]]+=sum;
	}
	for(int i=1;i <= m;i++){
		cout << cnt[i] << ' ';
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _ = 1;
//	scanf("%lld",&_);
	while(_--)solve();
	return 0;//0^0
}
