#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int a[N];
char c[N];
int sum=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int cntf=1,cntt=n;
	int cntfs=1,cntts=len;
	int flag=0;
	while(flag < (len+1)/2){
		int les=min(a[cntf],a[cntt]);
		if(c[cntf]!=c[cntt]){
			sum+=les;
			//cout<<sum<<endl;
		}
		//cout<<les<<endl;	
		a[cntf]-=les;
		a[cntt]-=les;
		flag+=les;
		if(a[cntf]==0){
			cntf++;
		}
		if(a[cntt]==0){
			cntt--;
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
