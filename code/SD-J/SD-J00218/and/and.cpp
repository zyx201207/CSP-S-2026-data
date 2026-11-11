#include <bits/stdc++.h>
using namespace std;
long long a[200005],ans=-1e9,n,m,f[200005];
long long w[21];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	w[0]=1;
	for(int i=1;i<=20;i++){
		w[i]=w[i-1]*2;
	}
	int f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if((a[i]==w[0])||(a[i]==w[1])||(a[i]==w[2])||(a[i]==w[3])||(a[i]==w[4])||(a[i]==w[5])||(a[i]==
		w[6])||(a[i]==w[7])||(a[i]==w[8])||(a[i]==w[9])||(a[i]==w[10])||
		(a[i]==w[11])||(a[i]==w[12])||(a[i]==w[13])||(a[i]==w[14])||(a[i]==w[15])
		||(a[i]==w[16])||(a[i]==w[17])||(a[i]==w[18])||(a[i]==w[19])){
			continue;
		}else{
			f1=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if((a[i]==w[0]-1)||(a[i]==w[1]-1)||(a[i]==w[2]-1)||(a[i]==w[3]-1)||(a[i]==w[4]-1)||(a[i]==w[5]-1)||(a[i]==
		w[6]-1)||(a[i]==w[7]-1)||(a[i]==w[8]-1)||(a[i]==w[9]-1)||(a[i]==w[10]-1)||
		(a[i]==w[11]-1)||(a[i]==w[12]-1)||(a[i]==w[13]-1)||(a[i]==w[14]-1)||(a[i]==w[15]-1)
		||(a[i]==w[16]-1)||(a[i]==w[17]-1)||(a[i]==w[18]-1)||(a[i]==w[19]-1)){
			continue;
		}else{
			f2=0;
			
			break;
		}
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(f1){
		cout<<0;
		return 0;
	}else if(f2){
		ans=a[n];
		for(int i=n-1;i>n-m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	
	cout<<ans;
	return 0;
}
