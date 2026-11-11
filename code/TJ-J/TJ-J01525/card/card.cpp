#include <bits/stdc++.h> 

using namespace std;
int a[500005];
int t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r;
	bool f=1;
	for(int i=1;i<=n;i++){
		l=i,r=n;
		while(l<=r){
			f=1;
			for(int j=r;j>l;j--){
				if(a[j]==a[l]){
					t[a[l]]++;
					l=j+1;
					f=0;
					break;
				}
			}
			if(f){
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
