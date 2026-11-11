#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N][5],ans;
signed main(){
	ioi;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i][1]=x;
		a[i][2]=c-'a'+1;
	}
	int i=1,j=n;
	while(i<j){
		if(a[i][2]!=a[j][2]){
			if(a[i][1]>a[j][1]){
				ans+=a[j][1];
				a[i][1]-=a[j][1];
				j--;
			} 
			else if(a[i][1]<a[j][1]){
				ans+=a[i][1];
				a[j][1]-=a[i][1];
				i++;
			}
			else ans+=a[i][1],i++,j--;
		}
		else{
			if(a[i][1]>a[j][1]){
				a[i][1]-=a[j][1];
				j--;
			} 
			else if(a[i][1]<a[j][1]){
				a[j][1]-=a[i][1];
				i++;
			}
			else i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
