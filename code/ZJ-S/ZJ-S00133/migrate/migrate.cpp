#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,n[2000010],s,m[2000010],o[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>a;
	while(a--){
		cin>>b>>c;
		for(int i=0;i<b;i++){
			cin>>n[i];
		}
		s=0;
		for(int i=0;i<b;i++){
			m[i]=1;
			o[i]=0;
			for(int j=i+1;j<b;j++){
				o[j]=10000000;
				m[j]=0;
			}
			for(int j=i+1;j<b;j++){
				for(int k=j-1;k>=i;k--){
					if(n[k]+c<n[j]){
						break;
					}
					o[j]=min(o[j],o[k]+1);
				}
				for(int k=j-1;k>=i;k--){
					if(n[k]+c<n[j]){
						break;
					}
					if(o[k]+1!=o[j]){
						continue;
					}
					m[j]+=m[k];
					if(m[j]>2){
						break;
					}
				}
				if(!m[j]){
					break;
				}
				if(m[j]==2){
					s++;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
