#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	int ans=a[0];
	for(int i=0;i<m;i++){
		ans&=a[i];
        cout<<a[i]<<"\n";
	}
	cout<<ans;
	return 0;
}
