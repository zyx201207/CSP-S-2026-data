#include <bits/stdc++.h>
using namespace std;
int a[500005];
int s[300005];
int k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[a[i]+1]=0){
			k[a[i]+1]++;
			s[a[i]+1]=;
		}else {
			for(int i=1;i<=s[a[i]+1];i++){
				a[i]=0;
			}
		}
	}
	return 0;
}