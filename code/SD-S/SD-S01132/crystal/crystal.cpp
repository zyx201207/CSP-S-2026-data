#include<bits/stdc++.h>
using namespace std;
int n,ans,te=1;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]&&i-2>=0) te=0;
	}
	if(te){
		int maxx=1;
		long long w=0;
		for(int i=n/2;i>0;i--){
			w+=a[n/2+1]-a[i];
			if(w<=m) maxx++;
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long w=0;
		int maxx=1;
		for(int j=i-1;j>0;j--){
			w+=a[i]-a[j];
			if(w<=m) maxx++;
			else break;
			//cout<<w<<" "<<maxx<<"  ";
		}
		
		ans=max(maxx,ans);//cout<<endl<<ans<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

