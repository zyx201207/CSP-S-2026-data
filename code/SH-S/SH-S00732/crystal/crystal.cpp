#include<iostream>
#include<algorithm>
using namespace std;
const int maxN=500002;
const long long MAX=9223372036854775807;
long long a[maxN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long m,mi=MAX,n;
	cin>>n>>m;
	bool flag=true;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (mi==MAX){
			if (i==2) mi=a[i]-a[i-1];
		}else{
			if ((a[i]-a[i-1])!=mi) flag=false;
		}
	}
	if (flag){
		long long adn=m/mi,l=0,r=1000000,mid,now;
		adn=abs(adn);
		while (1){
			mid=(l+r)/2;
			now=mid*(mid+1);
			if (now<=adn*2 && (mid+1)*(mid+2)>adn*2) break;
			if (now>adn*2) r=mid;
			else if (now<adn*2) l=mid;
		}
		cout<<min(mid+1,n)<<endl;
		return 0;
	}
	int ps=pow(2,n);
	long long ans=0;
	for (int choice=0;choice<ps;++choice){
		for (int i=-20;i<=20;i++){
			long long now=0;
			for (int j=1;j<=n;j++){
				if ((choice>>(j-1))&1){
					if (i-a[j]<0){
						now=0;
						break;
					}
					else now+=i-a[j];
				}
			}
			if (now>m) break;
			if (now==0) continue;
			ans=max(ans,(long long)__builtin_popcount(choice));
		}
	}
	cout<<ans<<endl;
	return 0;
}

