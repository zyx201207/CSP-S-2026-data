#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+20;
long long n,m,a[N],ans,cnt,maxx=-0x3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=n/2;i<=n;i++){
		ans=0;
		cnt=0;
//		cout<<"out"<<" "<<i<<" "<<a[i]<<"\n";
		for (int j=1;j<=i;j++){
//			cout<<"in"<<" "<<j<<" "<<a[j]<<" "<<a[i]-a[j]<<" ";
			cnt+=a[i]-a[j];
			ans++;
			if(cnt>m){
				break;
			}
		}	
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 
