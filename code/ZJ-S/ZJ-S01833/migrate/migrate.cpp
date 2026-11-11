#include<bits/stdc++.h>
using namespace std;
long long c,t,cnt;
long long s[2000010],qz[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		for(int i=n;i>=1;i--){
			int r=i,fri=0,se=0,tr=0;
			while(s[r]-s[i]<=k&&r<=n){
//				cout<<r<<" "<<n<<" ";
				if(s[r+1]-s[r]>k){
					n=r;
				}
				tr=se;
				se=fri;
				fri=r;
				r++;
			}
			r--;
//			cout<<"\n";
//			cout<<r<<" "<<i<<" "<<r-i<<"\n";
			qz[i]=r-i;
			if(n-i>=3){
				cnt+=qz[se]-qz[tr]+1;
			}
//			cout<<qz[se]<<" "<<qz[tr]<<" "<<qz[i]<<" "<<cnt<<"\n";
		}
//		cout<<"\n";
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
