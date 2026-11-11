#include<bits/stdc++.h>
using namespace std;

long long cry[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>cry[i];
	}
	sort(cry+1,cry+1+n);
	long long ans=0;
	for(int i=n;i>1;i--){
		if(ans>n)break;
		long long aannss=0,newm=m;
		for(int j=i;j>=1;j--){
			if(newm>0){
				aannss++;
				newm=newm-(cry[i]-cry[j]);
			}
			else if(m<0){
			aannss--;
			break;}
			else break;
		}
		if(aannss>ans)ans=aannss;
	}
	cout<<ans;
	return 0;
}