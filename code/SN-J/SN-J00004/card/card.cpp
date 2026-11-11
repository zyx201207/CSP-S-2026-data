#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+5;
int n,m,a[N],s[M],si[M],z[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			si[j]=s[j];
		}
		for(int j=i;j<=n;){
			if(si[a[j]]>=2){
				si[a[j]]--;
				int x=a[j];
				j++;
				while(a[j]!=x){
					si[a[j]]--;
					j++;	
				}
			}
			else
				j++;
		}
		s[a[i]]--;
		for(int j=1;j<=m;j++){
			if(si[j])z[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;
}
