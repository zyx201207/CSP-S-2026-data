#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
long long zy[5005];
long long ss[5005];
long long fx[5005];
long long p[5005];
long long dw[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	if (c==11 || c==12){
		while (t--){
			cin >> n >> d;
			for (int i=1;i<=n;i++){
				cin >> a[i];
			}
			if (n==1 || n==2 || n==3){
				cout << 0;
				continue;
			}
			long long ans=0;
			long long dc=a[2]-a[1];
			for (int i=4;i<=n;i++){
				if (i%2==0){
					if (d>=dc*(i/2) && (d<dc*(i/2+1))){
						ans+=(n-i+1);
					}
				}
			}
			cout << ans << '\n';
		}
		return 0;
	}
	else if (c==13 || c==14){
		while (t--){
			cin >> n >> d;
			for (int i=1;i<=n;i++){
				cin >> a[i];
			}
			long long xz1=a[1];
			long long xz2=a[n];
		
			long long dada=0;
			long long mm=1;
			for (int i=1;i<=n;i++){
				if (a[i]-xz1<=d && xz2-a[i]<=d){
					mm=i;
					break;
				}
			}
			long long mid=mm+1;
			for (int i=1;i<mm;i++){
				while (a[mid]-a[i]<=d){
					if (mid>n){
						break;
					}
					mid++;
				}
				if (mid>n){
					break;
				}
				dada+=n-mid+1;
			}
			cout << dada << '\n';
			//cout << mm;
		}
		return 0;
	}
	while (t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> a[i];
		}
		for (int i=1;i<=n;i++){
			ss[i]=0;
			dw[i]=0;
		}
		for (int i=1;i<=n;i++){
			long long last=i;
			for (int j=i+1;j<=n;j++){
				if (a[j]-a[i]>d){
					break;
				}
				last=j;
			}
			zy[i]=last;
			ss[last]+=ss[i]+1;
		}
		for (int i=n;i>=1;i--){
			long long lll=i;
			for (int j=i-1;j>=1;j--){
				if (a[i]-a[j]>d){
					break;
				}
				lll=j;
			}
			fx[i]=lll;
			dw[lll]+=dw[i]+1;
		}
		long long miao=0;
		for (int i=1;i<=n;i++){
			//cout << miao << '\n';
			for (int j=1;j<=n;j++){
				p[j]=0;
			}
			long long qw=zy[i];
			for (int j=qw;j>=i+1;j--){
				long long noww=zy[j];
				if (noww<=qw){
					break;
				}
				p[qw+1]++;
				p[noww+1]--;
			}
			long long cf=0;
			for (int j=qw+1;j<=n;j++){
				cf+=p[j];
				if (cf==2){
					if (cf+p[j+1]==0 && fx[i]!=fx[i+1]){
						miao+=(ss[i]+1)*(dw[j]+1);
					}
					else if(cf+p[j+1]!=0 && fx[i]!=fx[i+1]){
						miao+=(ss[i]+1);
					}
					else if (cf+p[j+1]==0 && fx[i]==fx[i+1]){
						miao+=(dw[j]+1);
					}
					else{
						miao+=1;
					}
				}
			}
		}
		cout << miao << '\n';
	}
	return 0;
}