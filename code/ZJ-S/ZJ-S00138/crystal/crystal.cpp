#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],d[N],s[N],f[N],ff[N];
bool isA=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+i;
		if(a[i]!=i)isA=0;
	}
	if(isA){//15pts
		if(m>s[n]){
			long long cha=(m-s[n])%n;
			cout<<max(cha,n-cha);
			return 0;
		}else if(m==s[n]){
			cout<<n;
			return 0;
		}else{//m<s[n]
			int k=lower_bound(s+1,s+1+n,m)-s;
			cout<<k-1;
			return 0;
		}
	}
	stable_sort(a+1,a+1+n);
	if(m==0){
		int tot=1,tmp=1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])tmp++;
			else{
				tot=max(tot,tmp);
				tmp=1;
			}
		}
		cout<<tot;
		return 0;
	}
	//m!=0
	for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)f[i]=f[i-1]+d[i],ff[i]=ff[i-1]+d[i]*(i-1);
	long long ans=1;
	for(int i=1;i<n;i++){
		//the addition starts from a[i]
		if(m>=ff[n-1]-ff[i-1]){
			long long temp=(m-(ff[n-1]-ff[i-1]))%(n-i+1);
			if(temp!=0&&i==1)ans=max(ans,(long long)(n-1));
			else ans=max(ans,(long long)(n-i+1));
			continue;
		}
		int k=lower_bound(ff+i,ff+n,m+ff[i-1])-ff;
		long long tmp=m-(ff[k-1]-ff[i-1]);
		while(tmp>=d[k]*(k-i+1)&&k<n&&tmp>0){
			tmp-=d[k]*(k-i+1);
			k++;
		}
		if(k==n)k--;
		ans=max(ans,(long long)(k-i+1));
	}
	cout<<ans;
	return 0;
}