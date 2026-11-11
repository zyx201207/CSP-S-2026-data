#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000010],s[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>x[i];
		for(int i=2;i<=n;i++)	s[i]=x[i]-x[i-1];
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int f=0;
				if(x[j]-x[i]<=d)	continue;
				int sum=0;
				for(int k=i+1;k<=j;k++){
					if(s[k]>d){
						f=1;
						break;
					}
					sum+=s[k];
				}
				if(f)	continue;
				if(sum%d==d-1)		cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
