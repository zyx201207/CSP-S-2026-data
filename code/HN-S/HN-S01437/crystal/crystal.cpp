#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int ma=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]>ma){
			ma=a[i];
		}
		//cout<<ma;
	}
	int qwe=0;
	for(int i=1;i<=ma;i++){
		if(qwe<b[i]){
			qwe=b[i];
			ma=i;
		}
		//cout<<qwe<<ma; 
	}
	sort(a+1,a+n+1);
	int qzb=0,hzb=n;
	for(int i=1;i<=n;i++){
		if(a[i]==ma){
			qzb=i;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]==ma){
			hzb=i;
			break;
		}
	}
	int costq=0,costh=0;
	int ls;
	int ls1=0;
	for(int i=qzb-1;i>=1;i--){
		ls=abs(ma-a[i]);
		ls1=0;
		if(costq+ls<=m){
			a[i]=0;
			costq+=ls;
			//cout<<costq<<ls1;
		}
	}
	int sl;
	int sl1=0;
	for(int i=hzb+1;i<=n;i++){
		sl=abs(ma-a[i]);
		sl1=0;
		if(costh+sl<=m){
			costh+=sl;
			a[i]=0;
		}
	}
	for(int i=qzb-1;i>=1;i--){
		if(a[i]==0){
			ls1++;
		}
	}
	for(int i=hzb+1;i<=n;i++){
		if(a[i]==0){
			sl1++;
		}
	}
	int jsq=qwe+ls1,jsh=qwe+sl1;
	if(jsq>jsh){
		cout<<jsq<<endl;
		return 0;
	}
	cout<<jsh<<endl;
// 5 8 -3 -1 2 2 7
	return 0;
} 
