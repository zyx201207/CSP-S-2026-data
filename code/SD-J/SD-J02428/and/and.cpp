#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],v[300005],b[100];
int maxx=-1000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=1;
		c=1;
		for(int j=1;j<=30;j++){
			if((a[i]&c)>0){
				maxx=max(maxx,j);
				b[j]++;
			}
			c=c*2;
		}
	}
	/*for(int i=1;i<=30;i++){
		cout<<b[i]<<' ';
	}
	cout<<endl;*/
	long long s=n;
	for(int k=maxx;k>=1;k--){
		if(b[k]>=m){
			int kk=1<<(k-1);
			//cout<<kk<<endl;
			for(int i=1;i<=n;i++){
				if(v[i]==1){
					if((a[i]&kk)==0){
						c=1;
						for(int j=1;j<=k;j++){
							if((a[i]&c)>0){
								b[j]--;
							}
							c=c*2;
						}
						v[i]=0;
						s--;
					}
				}
			}
		}
		if(s<m){
			break;
		}
	}
	long long sum=-1;
	for(int i=1;i<=n;i++){
		//cout<<v[i]<<' ';
		if(v[i]==1){
			if(sum==-1){
				sum=a[i];
			}
			else{
				sum=sum&a[i];
			}
		}
	}
	cout<<sum;
	return 0;
}
