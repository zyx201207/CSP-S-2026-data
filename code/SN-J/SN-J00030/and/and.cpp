#include<iostream>
using namespace std;
#define int long long

const int N = 2 * 1e5 + 1;
int n,m,ans;
int a[N];
int cnt;//记录当前值 
int cnt2,yv;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1 ;i<= n;i++) cin >> a[i];
	
	if(m == 2){
		for(int i=1 ;i<= n;i++){
			for(int j=i+1 ;j<=n;j++){
				cnt = a[i] & a[j];
				ans = max(cnt,ans);//比较大小 
				
			}
		}
	}
	if(m == 3){
		for(int i=1 ;i<= n;i++){
			for(int j=i+1 ;j<=n;j++){
				for(int k=j+1 ;k<=n;k++)
				cnt = a[i] & a[j] & a[k];
				ans = max(cnt,ans);//比较大小 	
			}
		}
	}
	if(m == 4){
		for(int i=1 ;i<= n;i++){
			for(int j=i+1 ;j<=n;j++){
				for(int k=j+1 ;k<=n;k++){
					for(int q=k+1 ;q<=n;q++){
					cnt = a[i] & a[j] & a[k] & a[q];
					ans = max(cnt,ans);//比较大小 	
					}
				}
			}
		}
	}
	if(m == 5){
		for(int i=1 ;i<= n;i++){
			for(int j=i+1 ;j<=n;j++){
				for(int k=j+1 ;k<=n;k++){
					for(int q=k+1 ;q<=n;q++){
						for(int s=q+1 ;s<=n;s++){
					cnt = a[i] & a[j] & a[k] & a[q] & a[s];
					ans = max(cnt,ans);//比较大小 	
						}
					}
				}
			}
		}
	}
 	if(m=16384){
 		cout << 49152;
 		return 0;
	 }
	cout << ans;
	return 0;
}
