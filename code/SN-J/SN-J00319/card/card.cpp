#include<bits/stdc++.h> 
using namespace std;
long long n,m,q[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int a[m+5];
	for(int i=1;i<=n;i++){
		cin >> a[i];
		q[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			q[j]=a[j];
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(q[k]==q[j]){
					for(int t=k;t<j;t++)
						q[t]-=q[t];
				}
			}
		}
		for(int j=i;j<=n;j++)
			if(q[j]!=0){
				for(int t=1;t<=m;t++)
					if(q[j]==t) ans[t]++;
			}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
