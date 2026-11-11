#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,cnt;
long long l[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=0;z<t;z++){
		cnt=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>l[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n-1;j++){
				if(l[j]-l[i]==d-1&&l[j+1]-1==l[j]){
					for(int s=j;s<n;s++){
						if(l[s]-l[i]==2*d-1){
							cnt++;
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
