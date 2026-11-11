#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[2000010];
bool check(int i,int j){
	if((j-i)%d==1 && d%2==0){
		return 1;
	}else if((j-i)%d==1 && n%2==0 && d%2==1){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int flag=0;
		for(int i=2;i<=n;i++){
		    if(a[i]-a[i-1]>d){
				n=i-1;
				break;
			}
		}
		for(int i=a[1];i<=a[n];i++){
			for(int j=i+d+1;j<=a[n];j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

