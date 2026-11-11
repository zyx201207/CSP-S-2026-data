#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
long long a[2000010];

int main(){
	freopen("migratc.in","r",stdin);
	freopen("migratc.out","w",stdout);
	long long c,t; 
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d,num=0;
		cin>>n>>d;
		int l=1,r=n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		//if(c==11||c==12){//11,12
			while(r>=1){
				for(int j=l;j<=r;j++){
					//cout<<a[r]<<' '<<a[j]<<' '<<a[r]-a[j]<<'\n';
					
					if(a[r]-a[j]<=d){
					//	cout<<1<<'\n';
						continue;
					}
					else if(a[r]-a[j]==d+d-a[2]+a[1]&&a[r]-a[j]>d&&r-j>=2){
						//cout<<a[r]<<' '<<a[j]<<' '<<a[r]-a[j]<<'\n';
						num++;
					}
				}
				r--;
			}
			
		//}
		
		cout<<num<<'\n';
	}
	return 0;
}