#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	int l=m;
	for(int i=1;i<=n/2;i++){
		int h=a[n/2]-a[n/2-i];
		int p=a[n/2]-a[n/2+i];
		if(l-h>0){
			l-=h;
			ans++;
			if(l-p>0){
				l-=p;
				ans++;
			}else if((l-p)==0){
				cout<<ans+1<<endl;
				return 0;
			}
		}else if(l-h==0){
			cout<<ans+1<<endl;
			return 0;
		}else{
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}

