#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
int n,m,sum[N];
int a[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		for(int j=1;j<=n;j++){
			if(s[j]==s[j+i]) {
				for(int f=s[j];f<=s[j+i];f++){
					s[f]=0;
				}
			}
		}
		for(int w=1;w<=m;w++){
			if(s[w]==w) sum[w]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
