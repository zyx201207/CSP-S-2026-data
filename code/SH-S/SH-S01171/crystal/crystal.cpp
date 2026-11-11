#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans=1;
int m,a[N],cha;
bool f1=1,f2=1;
int check(int x){
	int cn=1;
	long long mm=m;
	while(mm>=0&&cn<x){
		if (mm>=a[x]-a[x-cn]){
			mm-=a[x]-a[x-cn];
			cn++;
		}else break;
	}
	return cn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=i) f1=0;
		if (i==2) cha=a[i]-a[i-1];
		else if (i>2&&cha!=a[i]-a[i-1]) f2=0;
	}
	if (f1){//a[i]=i
		int i=1;
		while(m>=0){
			m-=i;
			if (m>=0) i++;
		}
		cout << i;
	}else if (f2){
		int i=cha,cnt=1;
		while(m>=0){
			m-=i;
			if (m>=0){
				i+=cha;
				cnt++;
			}
		}
		cout << cnt;
	}else{
		sort(a+1,a+n+1);
		for (int i=2;i<=n;i++){
			ans=max(check(i),ans);
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
