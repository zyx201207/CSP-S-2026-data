#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sort(a+1,a+1+n);
		if(a[i]==a[i+1]){
			cnt++;
			m--;
		}else{
			a[i]+=1;
			m--;
			}
			if(m<0){
				break;
			}
		}
	cout<<cnt;
	return 0;
}
