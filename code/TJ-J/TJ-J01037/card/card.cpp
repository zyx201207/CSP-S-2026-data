#include<bits/stdc++.h>
using namespace std;
const int N=5e5+6767;
int n,m;
int a[N],s[N],id[N],t[N];
int main(){
//	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=i;j<=n;j++){
			id[a[j]]++; 
			if(id[a[j]]>1) cnt++;
			s[j]+=cnt;
		}
		for(int j=n-1;j>=1;j--){
			if(s[j]==s[n]) t[a[j]]++;
			id[j]=0;s[j]=0;
		}
		id[n]=0,s[n]=0;
		t[a[n]]++;
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
