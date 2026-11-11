#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
#define N 200005
using namespace std;//44pts
int n;
int a[N];
char c[N][2];
int cnt[30];
int len;
ll na[N];
char nc[N];
int m;
ll ans;
int maxa;
int suml[N],sumr[N];
char s[100005];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",a+i,c[i]);
		cnt[c[i][0]-'a']+=a[i];
		len+=a[i];
		maxa=max(maxa,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(c[i][0]!=nc[m]){
			++m;
			nc[m]=c[i][0];
			na[m]+=a[i];
		}else{
			na[m]+=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		suml[i]=suml[i-1]+na[i];
	}
	for(int i=m;i>=1;i--){
		sumr[i]=sumr[i+1]+na[i];
	}
	if(m==1){//4pts
		printf("0");
		return;
	}
	if(maxa<=1){//20pts
		sort(cnt,cnt+26);
		printf("%d",n-cnt[25]);
		return;
	}
	//20pts
	vector<char>s(len+1);
	for(int i=1,k=1;i<=m;i++){
		for(int j=0;j<na[i];j++){
			s[k++]=nc[i];
		}
	}
	for(int i=1;i<=(len>>1);i++){
		if(s[i]!=s[len-i+1]){
			ans++;
		}
	}
	printf("%lld",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
