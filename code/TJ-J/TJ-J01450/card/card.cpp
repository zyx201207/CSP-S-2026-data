#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n;
	cin>>m;
	long long a[n+1],s[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r[n+1]={0};
		int t=0;
		for(int j=i;j<=n;j++){
			for(int h=0;h<=j;h++){
				if(r[h]==a[j]){
					for(int g=h;g<=j;g++){
						r[g]=0;
					}
					t=h;
				}
			}
			r[t]=a[j];
			t++;
		}
		for(int j=0;j<t;j++){
			s[r[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
} 
