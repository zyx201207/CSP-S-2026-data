#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5; 
int a[N];
char c[N];
string n;
int len,cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++){
			n+=c[i];
		}
	}
	n=" "+n;
	if(len%2==0){
		for(int l=1,r=len;l+1!=r;l++,r--){
			if(n[l]!=n[r]){
				cnt++;
			}	
		}
	}else{
		for(int l=1,r=len;l<r;l++,r--){
			if(n[l]!=n[r]){
				cnt++;
			}	
		}
	}
	int flag=0;
	if(m%2==0){
		int mid=m/2;
		for(int i=2;i<=mid;i++){
			if(n[i]!=n[i-1]){
				flag=1;
			}
		}
		if(flag==0){
			flag=0;
			for(int i=mid+2;i<=m;i++){
				if(n[i]!=n[i-1]){
					flag=1;
				}
			}
			if(flag==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

