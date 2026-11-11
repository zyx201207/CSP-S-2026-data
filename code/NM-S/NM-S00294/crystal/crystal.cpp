#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,sumn;
long long m,sum,maxn=-0x3f3f3f3f3f3f3f3f;
long long a[N],s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0){
		int mm=-1,cnt=0;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;
			}else{
				mm=max(mm,cnt);
				cnt=0;
			}
		}
	}
	for(int i=2;i<=n;i++){
		sum=0,sumn=0,maxn=-0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<i;j++){
			sum+=a[j]-a[j-1];
			s[j]=sum;
		}
		if(sum<=m){
			if(maxn<=sum){
				sumn=i-1;
				maxn=sum;
			}
		}else{
			int j=1;
			sort(s+1,s+n+1);
			for(int k=1;k<=n;k++){
			}
			while(sum>m&&j<=n){
				sum=sum-s[j];
				sumn++;
				j++;
			}

		}
	}
	cout<<sumn;
	return 0;
}
