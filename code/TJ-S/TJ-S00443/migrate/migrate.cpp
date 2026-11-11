#include<bits/stdc++.h>
using namespace std;
int a[100005],s[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		s[1]=0;
		cout<<s[1]<<" ";
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]+a[i]-a[i-1];
			//cout<<s[i]<<" ";
		}
		cout<<endl;
		int l=1;
		int cnt=0;
		int r;
		for(int len=1;len<=n;len++){
			for(int l=1;l+len-1<n;l++){
				r=l+len-1;
				int shang=1,now=1;
				{
					if(s[k]-s[shang-1]<=d){
						now++;
					}else{
						shang=now;
					}
				} 
			}
		} 
		cout<<cnt<<endl;
	}
}
