#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],sum=0,flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		flag=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==i){
				flag=0;
				break;
			}
			else{
				b[a[j]]=i;
			}
		}
		if(flag){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}/*
4 3
1 2 1 3

3 1 4

*****

10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/
