#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,num;
long long a[500005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int k=i,qwe=m;
		num=0;
		while(qwe>0){
			k++;
			if(k<=n){
				num++;
				m-=(a[i]-a[k]);
			}
			else break;

		}
		ans=max(ans,num);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
