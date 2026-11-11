#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],b[500003];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		bool t[500003];
		for(int i=1;i<=500003;i++)t[i]=0;
		for(int i=k;i<=n;i++){
			if(t[a[i]]){
				int j=i;
				while(t[a[i]]){
					t[a[--j]]=0;
				}
			}
			t[a[i]]=1;
		}
		for(int i=1;i<=n;i++)b[t[i]]++;
	}
	for(int i=1;i<=n;i++)cout<<b[i]; 
	return 0;
}
