#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[N];
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	int cnt[N]={};
	for(int i=1;i<=n;i++){
		bool f[N]={};
		for(int j=i;j<=n;j++){
			if(a[j]!=a[n]){
				if(f[a[j]]==1) cnt[j]--;
				else{
					cnt[j]++;
					f[a[j]]=1;	
				}
			}
			else break;
		}
	}
	cnt[a[n]]=n;
	for(int i=1;i<=n;i++){
		cout << cnt[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
