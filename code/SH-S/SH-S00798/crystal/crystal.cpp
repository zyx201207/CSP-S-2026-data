#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int p=m,cnt=0;
			for(int k=i;k<=j;k++){
				if(k==j){
					cnt=j-i+1;
//					cout<<cnt<<" ";
				}
				if(p-(a[j]-a[k])>=0){
					p=m-(a[j]-a[k]);
					
				}else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
//		cout<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


