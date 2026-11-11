//wangyihao tieyizhong SN-J00729
#include<bits/stdc++.h>
using namespace std;
long long a[20005];
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m=1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
