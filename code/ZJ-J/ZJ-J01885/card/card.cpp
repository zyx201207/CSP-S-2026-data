#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int num[1000005];
int cnt[300004];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int t=n;
	while(t--) {
		int at=0;
		int nt=0;
		for(int i=0; i<n; i++) {
			if(a[i]!=0) {
				at++;
			}
		}

		for(int i=0; i<at; i++) {
			num[i]=a[i];
			for(int j=0; j<i; j++) {
				if(num[j]==num[i] && num[j]!=0) {
					for(int k=j+1; k<=i;k++) {
						if(num[k]!=0){
							a[k]=num[k];
							num[k]=0;
							
						}
					}
				}
			}
		}
		for(int i=0; i<n; i++) {
			if(num[i]!=0) {
				nt++;
			}
		}
		for(int i=0; i<n; i++) {
			if(num[i]!=0){
				cnt[num[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}

	return 0;
}