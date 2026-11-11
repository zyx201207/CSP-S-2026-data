#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
const int M=300005;
int n,m,aa;
int a[N];
int anow[N];
int cd[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		anow[i]=a[i];
	}
	if(m==1){
		cout<<n<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]==1&&a[1]==1){
					aa=1;
				}
				if(a[j]==1&&a[1]==2){
					aa=2;
				}
				if(a[j]==2&&a[1]==1){
					aa=1;
				}
				if(a[j]==2&&a[1]==2){
					aa=2;
				}
			}
			if(aa==1&&a[1]==1){
				cd[1]++;
			}
			if(aa==1&&a[1]==2){
				cd[2]++;
			}
			if(aa==2&&a[1]==1){
				cd[1]++;
				cd[2]++;
			}
			if(aa==2&&a[1]==2){
				cd[1]++;
				cd[2]++;
			}
		}
		cout<<cd[1]<<" "<<cd[2]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cd[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<cd[i]<<" ";
	}
	cout<<endl;
	return 0;
}

