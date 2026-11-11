#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],t[300005],v[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		v[i]=t[a[i]],t[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[j]){
				int z=a[j++];
				while(a[j]!=z)j++;
				j--;
			}
			else ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
//9:30-10:30 i don't know so i just baoli(n^3)
//10:30-11:00 i write a n^2 baoli but it has a big bug
//11:07 debug succeed
//11:27 i think 11:30 is finish time,so i write my byte card and freopen
