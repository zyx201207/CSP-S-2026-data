#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int tot = 0;
int na[200005];
char nc[200005];
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum = 0;
	for(int i = 1;i<=n;i++){
		cin>>na[i]>>nc[i];
//		cerr<<i<<" ";
		sum+=na[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int cnt = 0,lst = 0;
	for(int i = 1;i<=n;i++){
		cnt+=na[i];
//		cout<<cnt<<" "<<sum/2<<" "<<lst<<'\n';
		if(lst<sum/2&&sum/2<=cnt){
			a[++tot] = sum/2-lst;
			c[tot] = nc[i];
			a[++tot] = cnt-sum/2;
			c[tot] = nc[i];
			lst = cnt;
			continue;
		}
		if(nc[i]==c[tot])a[tot]+=na[i];
		else a[++tot]=na[i],c[tot]=nc[i];
		lst = cnt;
	}
	for(int i = 1;i<=tot;i++){
//		cout<<i<<" ";
//		cout<<a[i]<<" "<<c[i]<<'\n';
	}
	if(tot==0){
		cout<<0;
		return 0;
	}
	int l = 1,lc = a[1];
	int r = tot,rc = a[tot];
	int ans = 0;
	while(l<r){
		if(c[l]==c[r]){
			if(lc>rc){
				lc-=rc;
				r--;
				rc = a[r];
			}else if(rc>lc){
				rc-=lc;
				l++;
				lc = a[l];
			}else{
				l++,r--;
				rc = a[r];
				lc = a[l];
			}
		}else{
			if(lc>rc){
				ans+=rc;
				lc-=rc;
				r--;
				rc = a[r];
			}else if(rc>lc){
				ans+=lc;
				rc-=lc;
				l++;
				lc = a[l];
			}else{
				ans+=lc;
				l++,r--;
				rc = a[r];
				lc = a[l];
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
11
1 a
1 b
2 c
1 d
1 e
2 f
1 g
1 h
1 i
1 k
1 a
*/
