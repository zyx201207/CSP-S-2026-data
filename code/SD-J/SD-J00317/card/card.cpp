#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[500010],b[500010],t[300010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(t[a[i]]!=0){
			b[t[a[i]]]=i;
		}
		t[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		t[i]=0;
	}
	if(m==2){
		if(a[n]==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2){
					cnt++;
				}
			}
			cout<<n<<" "<<cnt;
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<n<<" "<<cnt;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l!=n+1){
			if(b[l]!=0){
				l=b[l];
				continue;
			}else{
				t[a[l]]++;
				l++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
