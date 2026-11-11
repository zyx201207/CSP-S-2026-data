#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long t[n];
	long long t1=0;
	long long x;
	int tai=0;
	long long cnt[m+1];
	for(int j=1;j<=n;j++){
		for(int p=j;p<=n;p++){
			for(int q=0;q<=t1;q++){
				if(t[q] == a[j]){
					x=q;
					tai=1;
					break;
				}
			}
			if(tai){
				for(int l=x;l<=t1;l++){
					t[l]=0;
				}
				t1=x-1;
			}
			t[t1+1]=a[j];
			t1=t1+1;
			tai=0;
		}
		for(int o=0;n<=t1;o++){
			cnt[t[o]]++;
		}
	}
	for(int h=1;h<=m-1;h++){
		cout<<cnt[h]<<" ";
	}
	cout<<cnt[m];
	return 0;
}
