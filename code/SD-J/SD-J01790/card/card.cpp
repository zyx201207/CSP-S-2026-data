#include<iostream>
#include<cstring>
#include<stack>
#define int long long
using namespace std;
int powed[35];
int flag[500005],ans[500005],fals[500005];
int a[500007];
stack <int> f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	powed[1]=1;
	for(int i=1;i<=500005;i++){
		fals[i]=n;
	}
	for(int i=n;i>=1;i--){
		ans[a[i]]=max(ans[a[i]],i);	
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int res=0;
	for(int i=n;i>=1;i--){
		if(i==n) {
			ans[a[i]]=n;	
			fals[a[i]]=-1;
		}
		else if(i==1) ans[a[i]]+=1;
		else {
			for(int j=i-1;j>=1;j--){
				if(flag[a[j]]==1&&j<fals[a[i]]){
					if(fals[a[i]]<i)
					ans[a[i]]+=fals[a[i]]-j;
					else ans[a[i]]+=i-j;
					fals[a[i]]=j;
					res=1;
					break;
				}
			}
			if(res==0){
				ans[a[i]]+=i;
			}
			res=0;
		}
		flag[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
