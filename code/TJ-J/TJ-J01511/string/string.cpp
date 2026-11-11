#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[1000000005],n,num=0;
	char c[100005],zzz,xxx; 
	cin>>n>>endl;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]>>endl;
		for(int j=0;j<a[i];j++){
			zzz[j]=c[i];
			xxx[j]=zzz[j];
			swap(xxx[j],xxx[c[i-j]]);
			if(xxx[j]=zzz[j]){
				continue;
			}
			else{
				num+=1;
			}
		}
	}
	cout<<num;
	return 0;
}
