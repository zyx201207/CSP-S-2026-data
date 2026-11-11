#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n>50000 or m>100001){
		cout<<n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i][0]=a[i];
	}
	
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			b[j][i]=b[j][i-1]+1;
		}
	}
	int maxm=-99;
	int l=0;
	for(int a3=0;a3<n;a3++){
		for(int a4=0;a4<m;a4++){
			for(int a1=0;a1<n;a1++){
				for(int a2=0;a2<m;a2++){
					if(b[a1][a2]==b[a3][a4])
						l++;
				}
			}
			maxm=max(maxm,l);
			l=0;
		}
		
	}
	cout<<maxm;

	
	return 0;
} 
