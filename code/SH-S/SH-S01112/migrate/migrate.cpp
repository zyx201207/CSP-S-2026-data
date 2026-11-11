#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll d,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int num_double=0;
		for(int i=0;i<n;i++)   cin>>x[i];
		for(int len=4;len<=n;len++){
			for(int i=0;i+len-1<n;i++){
				int j=i+len-1,cnt=0;
				for(int k=i+1;k<j;k++){
					if(x[k]-x[i]<=d && x[j]-x[k]<=d)   cnt++;
				}
				if(cnt==2)   num_double++;
			}
		}
		cout<<num_double<<endl;
	}	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
