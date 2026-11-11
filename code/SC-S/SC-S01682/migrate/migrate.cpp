#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000001],b[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(j!=1){
				b[j]=a[j]-a[j-1];
			}
		}
		int s1=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				int bj=0,s=0;
				for(int k=u;k<=v-1;k++){
					if(b[k]<d){
						s+=b[k+1];
					}else{
						bj=1;
						break; 
					}
				}
				if(s>d&&3*d>=s&&bj==0&&s/2<2){
					s1++;
				}
			}
		}
		cout<<s1<<endl;
	}
	return 0;
} 