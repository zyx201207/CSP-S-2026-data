//wangyihao tieyizhong SN-J00729
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[50005],b[50005];
void dig(long long x){
	int p=0;
	for(int i=1+x-1;i<=n;i++){
		if(i==n){
			if(b[i]==i){
				p++;
			}
			cout<<p;
			return;
		}
		b[i-x+1]=a[i];
		for(int j=1;j<=i;j++){
			if(b[i-x+1]==b[j]){
				dig(i);
			}
		}
	}
}
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dig(i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
