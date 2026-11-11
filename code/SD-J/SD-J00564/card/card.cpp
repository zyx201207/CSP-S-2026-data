#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],s[M];
int st[N],tt,idx[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(idx[a[j]]){
				int x=idx[a[j]];
				for(int k=idx[a[j]];k<=;k++){
					st[k]=0;
					idx[k]=0;
				}
				tt-=tt-x+1;
				st[++tt]=a[j];
				idx[a[j]]=tt;
			}
		}
		for(int j=1;j<=m;j++){
			if(idx[j]){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
