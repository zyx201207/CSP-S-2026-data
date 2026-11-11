#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,ans=0,sum=0;
int a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int _=1;_<=t;_++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(13<=c && c<=14){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					if(abs(a[i]-a[j])<=d) ans++;
					else{
						if(ans!=2){
							ans=0;
							j=n;
						}
		                if(ans==2){
		                	sum++;
						}
					}
					if(ans>2) {
	                    j=n;
	                    ans=0;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

