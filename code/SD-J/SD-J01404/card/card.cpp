#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500086],t[500086],b[500086],t2[500086];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){b[j]=a[j];t[a[j]]++;}
			else {
				for(int k=i;k<j;k++){
					if(b[k]==a[j]){
						for(int kk=k;kk<j;kk++){
							t[b[kk]]--;
							b[kk]=0; 
						}
						break;
					}
				}
				t[a[j]]++;
				b[j]=a[j];
			}
		}
	
		for(int j=1;j<=m;j++){
			t2[j]+=t[j];
			t[j]=0;
		}
		for(int j=i;j<=n;j++)b[j]=0;
	} 
	for(int i=1;i<=m;i++){
		cout<<t2[i]<<' ';
	}
	return 0;
}

