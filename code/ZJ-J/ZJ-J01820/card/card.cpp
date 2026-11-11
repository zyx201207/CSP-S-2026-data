#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ap[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int l,r;
	for(int i=1;i<=n;++i){
		l=i;
		while(l<=n){
			int f=0;
			for(int j=l+1;j<=n;++j){
				if(a[l]==a[j]){
					r=j;
					f=1;
					break;
				}
			}
			if(f==0){
				ap[a[l]]++;
				l++;
			}else{
				l=r;						
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout << ap[i] << ' ';
	}
	return 0;
}
