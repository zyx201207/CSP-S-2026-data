#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[5005],ans[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s[3005];
	for(int i=1;i<=n;i++){
		bool ok[3005]={0};
		for(int j=0;j<=m;j++){
			ok[j]=0;
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[j]==a[k]&&!ok[k]){
					for(int z=k;z<j;z++){
						if(ok[z]){
							continue;
						}else{
							s[a[z]]--;
							ok[z]=1;
						}
					}
					break;
				}
			}
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
