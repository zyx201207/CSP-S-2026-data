#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,d,i,j,k,l,sum[100],a[5000100],c,t;
bool x=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(i=0;i<t;i++){
		cin>>n>>d;
		for(j=0;j<n;j++){
			cin>>a[j];
		}
		for(l=3;l<n;l++){
			for(j=1;j<=d;j++){
				x=0;
				for(k=0;k<l;k++){
					if(a[k+j]-a[k]<d)x=1;
				}
				if(x)sum[i]++;
			}
		}

	}
	for(k=0;k<t;k++){
		cout<<sum[k]-1<<endl;
	}
	return 0;
}

