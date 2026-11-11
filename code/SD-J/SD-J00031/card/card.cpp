#include<bits/stdc++.h>
using namespace std;
bool cnt[300050];
long long a[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	/*for(int i=0;i<n;i++){
		int a1[n-i+10];
		for(int j=i;j<n;j++){
			a1[j-i]=a[j];
			for(int k=)
		}
	}*/
	for(int i=0;i<n;i++){
		long long a1[n-i+10];
		for(int j=i;j<n;j++){
			a1[j-i]=a[j];
		}
		for(int j=i;j<n;j++){
			int k=j;
			while(k-i){
				k--;
				if(a1[k-i]==a1[j-i]){
					for(int q=k;q<j;q++){
						a1[q-i]=0;
					}
					break;
				}
			}
		}
		for(int j=0;j<n-i;j++){
			if(a1[j]!=0){
				cnt[a1[j]]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<cnt[i]<<" ";
	}
}
