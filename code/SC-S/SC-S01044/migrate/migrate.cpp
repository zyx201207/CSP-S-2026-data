#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,vis,sum;
long long a[2000005],b[2000005],g[2000005];
void s2(){
	long long mid,ans=0;
	for(int i=1;i<=n;i++){
		if(a[n]-a[i]<=d && a[i]-a[1]<=d){
			mid=i;
			break;
		}
	}
	for(int i=1;i<mid;i++){
		b[i]=a[i]+d;
	}
	long long l=1,r=mid+1;
	for(;;){
		if(l==mid){
			g[n]=n;
			break;
		}
		if(r>n){
			g[l]=n;
			l++;
			continue;
		}
		if(b[l]>=a[r]){
			r++;
		}else{
			g[l]=r-1;
			l++;
		}
	}
	for(int i=1;i<mid;i++){
		ans+=n-g[i];
	}
	cout << ans << endl;
}
void s1(){
	long long l=1,r=2,ans=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i]+d;
	}
	for(;;){
		if(l==n){
			g[n]=n;
			break;
		}
		if(r>n){
			g[l]=n;
			l++;
			continue;
		}
		if(b[l]>=a[r]){
			r++;
		}else{
			g[l]=r-1;
			l++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d){
				break;
			}
			if(a[j]-a[i]<=d){
				continue;
			}
			sum=1;
			vis=0;
			for(long long k=i;k<j;sum++){
				k=g[k];
			}
			for(int f=1;f<sum;f++){		
				for(long long k=i,w=1;w<sum;w++){
					k=g[k];
					if(w==f){
						k--;
					}
					if(w==sum-1 && k>=j){
						vis++;
					}
				}
			}
			if(vis==1){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		if(c==13 || c==14){
			s2();
		}else{
			s1();
		}
	} 
	return 0;
} 